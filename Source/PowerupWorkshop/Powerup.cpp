// Fill out your copyright notice in the Description page of Project Settings.


#include "Powerup.h"
#include "TimerManager.h"

APowerup::APowerup()
{
	duration = 2;
	isActive = false;
}

APowerup::APowerup(int inDuration)
{
	this->duration = inDuration;
	isActive = false;

}

APowerup::~APowerup()
{
}
void APowerup::Activate(UCharacterMovementComponent* inTargetMovementComponent) {
	this->targetMovementComponent = inTargetMovementComponent;
	isActive = true;

	FTimerDelegate TimerDelegate;
	TimerDelegate.BindUObject(this, &APowerup::Deactivate);


	//Cast<AActor>(this)->GetWorld()->GetTimerManager().SetTimer(
	//	handle, // handle to cancel timer at a later time
	//	this, // the owning object
	//	&IPowerup::Deactivate, // function to call on elapsed
	//	duration, // float delay until elapsed
	//	false); // looping?

	GetWorld()->GetTimerManager().SetTimer(
		handle, // handle to cancel timer at a later time
		TimerDelegate,
		duration, // float delay until elapsed
		false); // looping?
}

void APowerup::Deactivate() {

}

