// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "E1211XUNRGameMode.h"
#include "E1211XUNRHUD.h"
#include "E1211XUNRCharacter.h"
#include "UObject/ConstructorHelpers.h"

AE1211XUNRGameMode::AE1211XUNRGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AE1211XUNRHUD::StaticClass();
}
