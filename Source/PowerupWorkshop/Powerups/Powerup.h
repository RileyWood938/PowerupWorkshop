// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GameFramework/CharacterMovementComponent.h>
#include "Powerup.generated.h"

/**
 *
 */
UCLASS()
class POWERUPWORKSHOP_API APowerup : public AActor
{
	GENERATED_BODY()

public:
	APowerup();
	APowerup(int inDuration);
	~APowerup();
	bool IsActive();
	virtual void Activate(UCharacterMovementComponent* inTargetMovementComponent);
	virtual void Deactivate();

private:
	int duration;
	bool isActive;
	FTimerHandle handle;

protected:
	UCharacterMovementComponent* targetMovementComponent;

};
