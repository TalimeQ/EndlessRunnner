// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseObstacle.h"
#include "NegativeScoreObstacle.generated.h"

/**
 * 
 */
class AEndlessRunnerCharacter;

UCLASS()
class ENDLESSRUNNER_API ANegativeScoreObstacle : public ABaseObstacle
{
	GENERATED_BODY()
private:

	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	class UStaticMeshComponent* objectStaticMesh = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Score")
	int scoreTaken{ 0 };
protected:

    virtual void OnObstacleCollision_Implementation(AEndlessRunnerCharacter* endlessRunner) override;
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	bool bIsActive = true;
public:
	ANegativeScoreObstacle();

private:
	
		
};
