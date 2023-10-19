// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedPowerup.h"

// Sets default values
ASpeedPowerup::ASpeedPowerup() {
	// Our root component will be a sphere that reacts to physics
	USphereComponent* CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = CollisionComponent;
	CollisionComponent->InitSphereRadius(40.0f);
	CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	CollisionComponent->SetGenerateOverlapEvents(true); // Enable overlap events
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpeedPowerup::OnOverlapBegin);

}
ASpeedPowerup::ASpeedPowerup(int inDuration) {

}
ASpeedPowerup::~ASpeedPowerup() {

}
void ASpeedPowerup::Activate(UCharacterMovementComponent* inTargetMovementComponent) {
	//base::Activate(inTargetMovementComponent);
	targetMovementComponent->MaxWalkSpeed = 1000.0f;
}
void ASpeedPowerup::Deactivate() {
	targetMovementComponent->MaxWalkSpeed = 600.0f;
	delete(this);
}

void ASpeedPowerup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Screen Message"));

		// This code will be executed when the actor overlaps with another actor
		// You can implement your logic here.
	}
}