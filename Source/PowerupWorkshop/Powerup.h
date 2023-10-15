// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GameFramework/CharacterMovementComponent.h>

/**
 *
 */
class POWERUPWORKSHOP_API APowerup : public AActor
{
public:
	APowerup();
	APowerup(int inDuration);
	~APowerup();
	bool IsActive();
	void Activate(UCharacterMovementComponent* inTargetMovementComponent);
	void Deactivate();

private:
	UCharacterMovementComponent* targetMovementComponent;
	int duration;
	bool isActive;
	FTimerHandle handle;
};
