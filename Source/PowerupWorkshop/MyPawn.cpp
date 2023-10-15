// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/Vector.h"

#include "MyPawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 600.0f;
	FVector DesiredMovementThisFrame = FVector(0.0f, 100.0f, 0.0f);
}


void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyPawn::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyPawn::StopJump);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawn::MoveRight);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AMyPawn::MoveLeft);

}

void AMyPawn::StopJump() {
	
}


void AMyPawn::StartJump() {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Distance %f"), distanceToGround()));

	if (distanceToGround() < 150) {
		// Calculate the upward impulse force to apply
		FVector JumpImpulse = FVector(0.0f, 0.0f, 1000.0f); // Adjust the Z component as needed

		// Apply the impulse to the character
		//LaunchCharacter(JumpImpulse, false, false);
	}


}

void AMyPawn::MoveRight(float value){
	if (value != 0) {
		//LaunchCharacter(FVector(0.0f, 1.0f, 0.0f) * value, false, false);
	}
}

void AMyPawn::MoveLeft(float value) {
	if (value != 0) {
		const FRotator YawRotation(0, 90, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		//LaunchCharacter(Direction * value, false, false);
	}
}

float AMyPawn::distanceToGround() {
	FVector StartLocation = GetActorLocation();
	FVector EndLocation = StartLocation - FVector(0, 0, 1000);

	FHitResult HitResult;

	// Perform the raycast.
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility))
	{
		// A hit was detected.
		FVector ImpactPoint = HitResult.ImpactPoint;
		return FVector::Dist(StartLocation, ImpactPoint);


	}

	return 1000.0f;
}
