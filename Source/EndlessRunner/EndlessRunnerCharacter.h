// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EndlessRunnerCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnScored);

UCLASS(config=Game)
class AEndlessRunnerCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AEndlessRunnerCharacter();
	UPROPERTY(BlueprintAssignable)
	FOnScored OnScored;

protected:

	virtual void Tick(float deltatime) override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);
	void TurnNinety(float value);

	UPROPERTY(EditDefaultsOnly, Category = "Movement", BlueprintReadWrite)
		float movementSpeed = 1000.0f;

	UPROPERTY(Category = "Movement", BlueprintReadWrite)
		bool bCanPlay = true;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:


	UFUNCTION(BlueprintCallable, Category = "Score")
	void SetScore(int newScore);
	UFUNCTION(BlueprintPure, Category = "Score")
	int GetScore();
	/* Sets if player can turn */
	UFUNCTION(BlueprintCallable,Category = "Movement")
	void SetCanTurn(bool bNewValue);
	/* Returns turn value */
	UFUNCTION(BlueprintPure, Category = "Movement")
	bool GetCanTurn();

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
private:
	

	int score = 0;
	FRotator desiredRot{ 0,0,0};
};

