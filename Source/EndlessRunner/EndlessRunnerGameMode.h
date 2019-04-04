// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessRunnerGameMode.generated.h"

UENUM(BlueprintType)
enum class ECurrentGameState: uint8
{
	ECGS_IsPlaying,
	EGCS_IsFinished,
	EGCS_Unknown
};

UCLASS(minimalapi)
class AEndlessRunnerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEndlessRunnerGameMode();
protected:
	UPROPERTY(BlueprintReadWrite, Category = "GameState")
		ECurrentGameState currentGameState = ECurrentGameState::EGCS_Unknown;



};