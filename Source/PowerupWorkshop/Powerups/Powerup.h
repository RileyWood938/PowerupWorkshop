// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	virtual void Activate();
	virtual void Deactivate();
	virtual void Tick(float DeltaTime) override;

protected:
	int duration;
	bool isActive;


private:
	FTimerHandle handle;

};
