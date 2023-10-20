// Fill out your copyright notice in the Description page of Project Settings.


#include "Powerup.h"
#include "TimerManager.h"

APowerup::APowerup()
{
	duration = 2;
	isActive = false;
	PrimaryActorTick.bCanEverTick = true;

}

APowerup::APowerup(int inDuration)
{
	this->duration = inDuration;
	isActive = false;

}

APowerup::~APowerup()
{
}
void APowerup::Activate() {
	isActive = true;

	FTimerDelegate TimerDelegate;
	TimerDelegate.BindUObject(this, &APowerup::Deactivate);

	GetWorld()->GetTimerManager().SetTimer(
		handle, // handle to cancel timer at a later time
		TimerDelegate,
		duration, // float delay until elapsed
		false); // looping?
}

void APowerup::Tick(float DeltaTime) {
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Tick"));

	Super::Tick(DeltaTime);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Tick"));

}
void APowerup::Deactivate() {
	isActive = false;
}

bool APowerup::IsActive() {
	return isActive;
}

