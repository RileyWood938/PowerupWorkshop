// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedPowerup.h"
#include "GameFramework/Character.h"


// Sets default values
ASpeedPowerup::ASpeedPowerup() {
	// Our root component will be a sphere that reacts to physics
	USphereComponent* CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = CollisionComponent;
	CollisionComponent->InitSphereRadius(40.0f);
	CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	CollisionComponent->SetGenerateOverlapEvents(true); // Enable overlap events
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpeedPowerup::OnOverlapBegin);
	startingSpeed = 0;
	duration = 5;
}
ASpeedPowerup::ASpeedPowerup(int inDuration) {

}
ASpeedPowerup::~ASpeedPowerup() {

}
void ASpeedPowerup::Activate() {
	APowerup::Activate();
	startingSpeed = targetMovementComponent->MaxWalkSpeed;
	startingAcceleration = targetMovementComponent->MaxAcceleration;
	targetMovementComponent->MaxWalkSpeed = 15000.0f;
	targetMovementComponent->MaxAcceleration = 3048.0f;
}
void ASpeedPowerup::Deactivate() {
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Ended"));

	APowerup::Deactivate();
	targetMovementComponent->MaxWalkSpeed = startingSpeed;
	targetMovementComponent->MaxAcceleration = startingAcceleration;
	Destroy();
}

void ASpeedPowerup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && !isActive) {
		ACharacter* character = Cast<ACharacter>(OtherActor);
		if (character)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Started"));
			this->targetMovementComponent = character->GetCharacterMovement();
			Activate();
			// This code will be executed when the actor overlaps with another actor
			// You can implement your logic here.
		}
	}
}