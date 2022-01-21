// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPS_UE4GameMode.h"
#include "FPS_UE4HUD.h"
#include "FPS_UE4Character.h"
#include "UObject/ConstructorHelpers.h"

AFPS_UE4GameMode::AFPS_UE4GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPS_UE4HUD::StaticClass();
}
