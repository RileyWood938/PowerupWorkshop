// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Powerup.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpeedPowerup.generated.h"

UCLASS()
class POWERUPWORKSHOP_API ASpeedPowerup : public APowerup
{
	GENERATED_BODY()

public:	
	ASpeedPowerup();
	ASpeedPowerup(int inDuration);
	~ASpeedPowerup();
	virtual void Activate(UCharacterMovementComponent* inTargetMovementComponent) override;
	virtual void Deactivate() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
