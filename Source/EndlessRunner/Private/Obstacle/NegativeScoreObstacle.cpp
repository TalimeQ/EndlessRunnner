// Fill out your copyright notice in the Description page of Project Settings.

#include "NegativeScoreObstacle.h"
#include "EndlessRunnerCharacter.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h "


void ANegativeScoreObstacle::OnObstacleCollision_Implementation(AEndlessRunnerCharacter* endlessRunner)
{
	
	int punishedScore = endlessRunner->GetScore();
	punishedScore -= this->scoreTaken;
	
	endlessRunner->SetScore(punishedScore);
	this->DeactivateOnCol.Broadcast();
} 
ANegativeScoreObstacle::ANegativeScoreObstacle()
{
	objectStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Of Doom"));
	this->SetRootComponent(objectStaticMesh);
}
