// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Activates.generated.h"
/**
 * 
 */

UINTERFACE(BlueprintType)
class ENDLESSRUNNER_API  UActivates : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class ENDLESSRUNNER_API IActivates
{
	GENERATED_IINTERFACE_BODY()
public:
	//classes using this interface must implement ReactToHighNoon
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyCategory")
		bool Deactivate();

	//classes using this interface may implement ReactToMidnight
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "MyCategory")
		bool Activate();
};
