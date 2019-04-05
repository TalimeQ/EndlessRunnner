// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "EndlessRunnerGameMode.h"
#include "EndlessRunnerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEndlessRunnerGameMode::AEndlessRunnerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

}
TArray<int> AEndlessRunnerGameMode::updateScores(TArray<int> scoresToUpdate)
{
	TArray<int> updatedArray;

	scoresToUpdate.Sort([]( int A,  int B) {
		return A > B;
	});
	
	for (int u : scoresToUpdate)
	{
		UE_LOG(LogTemp, Warning, TEXT("Stored %d"), u);
	}
	for (int i = 0; i < 10; i++)
	{
		// What a terrible way to do it
		updatedArray.Add(scoresToUpdate[i]);
	}
	return updatedArray;
}