// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePickup.h"
#include "SlowerDownPickup.generated.h"

class AEndlessRunnerCharacter;
class UMovementComponent;
/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API ASlowerDownPickup : public ABasePickup
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly, Category = "Pickup Power")
	float fSlowDownAmount{ 0 };
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mesh")
	class UStaticMeshComponent* objMesh;

public:
	virtual void OnItemPickup(AEndlessRunnerCharacter* runnerCharacter) override;
	ASlowerDownPickup();

protected:
	UFUNCTION(BlueprintCallable)
	void getUpdatedSpeed(UMovementComponent * runnerMovement);
	
};
