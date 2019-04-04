// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseObstacle.h"
#include "EndlessRunnerCharacter.h"

// Sets default values
ABaseObstacle::ABaseObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseObstacle::OnObstacleCollision_Implementation(AEndlessRunnerCharacter* endlessRunner)
{
	UE_LOG(LogTemp, Warning, TEXT("OnObstacleCollision"))
}

//A bandaid somehow i cannot call native event after engine crash, dont really want to fix it atm
void ABaseObstacle::OnObstacleColl(AEndlessRunnerCharacter* characterRef)
{
	UE_LOG(LogTemp,Warning,TEXT("OnObstacleColl"))
	OnObstacleCollision(characterRef);
}