// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Powerup.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include <GameFramework/CharacterMovementComponent.h>
#include "HoverPowerup.generated.h"

/**
 * 
 */
UCLASS()
class POWERUPWORKSHOP_API AHoverPowerup : public APowerup
{
	GENERATED_BODY()

public:
	AHoverPowerup();
	AHoverPowerup(int inDuration);
	~AHoverPowerup();
	virtual void Activate() override;
	virtual void Deactivate() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	UCharacterMovementComponent* targetMovementComponent;
	float startingSpeed;
	float startingAcceleration;
	ACharacter* character;

};
