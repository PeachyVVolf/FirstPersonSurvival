// Copyright Epic Games, Inc. All Rights Reserved.

#include "FirstPersonGameGameMode.h"
#include "FirstPersonGameHUD.h"
#include "FirstPersonGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFirstPersonGameGameMode::AFirstPersonGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFirstPersonGameHUD::StaticClass();
}
