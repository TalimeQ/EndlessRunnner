// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseInteractable.generated.h"

class AEndlessRunnerCharacter;
UCLASS()
class ENDLESSRUNNER_API ABaseInteractable : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseInteractable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool bIsActive = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Deactivate() = 0;
	virtual void Activate() = 0;
};
