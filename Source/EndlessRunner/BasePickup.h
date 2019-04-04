// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndlessRunnerCharacter.h"
#include "BasePickup.generated.h"

// Will broadcast on item pickup event


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickup, class AActor*, OtherActor);

UCLASS()
class ENDLESSRUNNER_API ABasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintAssignable)
	FOnPickup OnPickup;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable,Category = "Pickup")
	virtual void OnItemPickup(AEndlessRunnerCharacter* runnerCharacter);

};
