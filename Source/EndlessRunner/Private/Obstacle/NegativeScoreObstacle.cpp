// Fill out your copyright notice in the Description page of Project Settings.

#include "NegativeScoreObstacle.h"
#include "EndlessRunnerCharacter.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h "


void ANegativeScoreObstacle::OnObstacleCollision_Implementation(AEndlessRunnerCharacter* endlessRunner)
{
	UE_LOG(LogTemp, Warning, TEXT("I WILL NEGATE WHAT YOU HAVE EARNED"));
	int punishedScore = endlessRunner->GetScore() - this->scoreTaken;
	endlessRunner->SetScore(punishedScore);
	this->SetActorHiddenInGame(true);
} 
ANegativeScoreObstacle::ANegativeScoreObstacle()
{
	objectStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Of Doom"));
	this->SetRootComponent(objectStaticMesh);
}
