// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterController.h"
#include "Math/Vector.h"

// Sets default values
ACharacterController::ACharacterController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach the spring arm component
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);  // Attach the spring arm to the root component
	SpringArmComponent->TargetArmLength = 1000;

	// Create and attach the camera component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);  // Attach the camera to the spring arm

	speedMultiplier = 5000;

}

// Called when the game starts or when spawned
void ACharacterController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterController::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacterController::StopJump);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACharacterController::MoveRight);
	PlayerInputComponent->BindAxis("MoveLeft", this, &ACharacterController::MoveLeft);
	
}

void ACharacterController::StopJump() {
	
}


void ACharacterController::StartJump() {
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Distance %f"), distanceToGround()));

	//if (distanceToGround() < 150) {
		Jump();
		//// Calculate the upward impulse force to apply
		//FVector JumpImpulse = FVector(0.0f, 0.0f, 1000.0f); // Adjust the Z component as needed

		//// Apply the impulse to the character
		//LaunchCharacter(JumpImpulse, false, false);
	//}


}

void ACharacterController::MoveRight(float value){
	if (value != 0.0f)
	{

		AddMovementInput(FVector(0,1,0), value);
	}
}

void ACharacterController::MoveLeft(float value) {
	if (value != 0.0f)
	{

		AddMovementInput(FVector(0,-1,0), value);
	}
}

float ACharacterController::distanceToGround() {
	FVector StartLocation = GetActorLocation(); 
	FVector EndLocation = StartLocation - FVector(0, 0, 1000); 

	FHitResult HitResult;

	// Perform the raycast.
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility))
	{
		// yA hit was detected.
		FVector ImpactPoint = HitResult.ImpactPoint;
		return FVector::Dist(StartLocation, ImpactPoint);


	}

	return 1000.0f;
}