// Copyright Epic Games, Inc. All Rights Reserved.

#include "PowerupWorkshopGameModeBase.h"
#include "CharacterController.h"

APowerupWorkshopGameModeBase::APowerupWorkshopGameModeBase()
{
     //Set the default pawn class
   DefaultPawnClass = ACharacterController::StaticClass(); // Replace with your character class

}
UClass* APowerupWorkshopGameModeBase::GetDefaultPawnClassForController_Implementation(AController* InController)
{
    // Return the default pawn class for the player controller

    return DefaultPawnClass;
}