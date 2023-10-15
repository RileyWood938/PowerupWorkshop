// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PowerupWorkshopGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class POWERUPWORKSHOP_API APowerupWorkshopGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
    APowerupWorkshopGameModeBase();

    // Override the default pawn class
    virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

};
