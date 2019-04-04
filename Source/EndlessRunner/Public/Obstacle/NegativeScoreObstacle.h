// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseObstacle.h"
#include "NegativeScoreObstacle.generated.h"

/**
 * 
 */
class AEndlessRunnerCharacter;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeactivate);

UCLASS()
class ENDLESSRUNNER_API ANegativeScoreObstacle : public ABaseObstacle
{
	GENERATED_BODY()
private:


	UPROPERTY(EditDefaultsOnly, Category = "Score")
	int scoreTaken{ 0 };
protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Mesh")
	class UStaticMeshComponent* objectStaticMesh = nullptr;

   

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	bool bIsActive = true;

public:
	ANegativeScoreObstacle();

	UPROPERTY(BlueprintAssignable)
	FDeactivate DeactivateOnCol;

protected:
	virtual void OnObstacleCollision_Implementation(AEndlessRunnerCharacter* endlessRunner) override;
	
		
};
