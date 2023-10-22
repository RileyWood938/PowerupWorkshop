// Fill out your copyright notice in the Description page of Project Settings.


#include "HoverPowerup.h"

#include "GameFramework/Character.h"


// Sets default values
AHoverPowerup::AHoverPowerup() {
	// Our root component will be a sphere that reacts to physics
	USphereComponent* CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = CollisionComponent;
	CollisionComponent->InitSphereRadius(40.0f);
	CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	CollisionComponent->SetGenerateOverlapEvents(true); // Enable overlap events
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AHoverPowerup::OnOverlapBegin);
	startingSpeed = 0;
	duration = 10;
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = false;
	PrimaryActorTick.TickGroup = TG_PrePhysics;

}
AHoverPowerup::AHoverPowerup(int inDuration) {

}
AHoverPowerup::~AHoverPowerup() {

}
void AHoverPowerup::Activate() {
	APowerup::Activate();

}
void AHoverPowerup::Deactivate() {
	APowerup::Deactivate();
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Hit"));

	Destroy();
}

void AHoverPowerup::Tick(float DeltaTime){

	Super::Tick(DeltaTime);


	if (isActive) {
			float upForce = ((1000 - character->GetActorLocation().Z));
			float dampingForce = character->GetVelocity().Z;
			if (dampingForce != 0) {
				upForce = upForce - (dampingForce * 0.4f);
			}
			FVector JumpImpulse = FVector(0.0f, 0.0f, upForce);

			character->LaunchCharacter(JumpImpulse, false, false);
	}
}

void AHoverPowerup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && !isActive) {
		character = Cast<ACharacter>(OtherActor);
		if (character)
		{
			Activate();
		}
	}
}