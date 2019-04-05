// Fill out your copyright notice in the Description page of Project Settings.

#include "SlowerDownPickup.h"
#include "EndlessRunnerCharacter.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/GameFramework/MovementComponent.h "
#include "../../Public/Pickups/SlowerDownPickup.h"

ASlowerDownPickup::ASlowerDownPickup()
{

	objMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Object Mesh"));
	
}

float ASlowerDownPickup::getUpdatedSpeed(UMovementComponent * runnerMovement)
{
	 float fCurrentRunnerSpeed = runnerMovement->GetMaxSpeed();
	 float fNewRunnerSpeed = fCurrentRunnerSpeed - fSlowDownAmount;
	 return fNewRunnerSpeed;
}

void ASlowerDownPickup::OnItemPickup(AEndlessRunnerCharacter * runnerCharacter)
{
	
	// Will be used to turn off pickup
	OnPickup.Broadcast(runnerCharacter);
}


