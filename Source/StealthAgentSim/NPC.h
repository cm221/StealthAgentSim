// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "NPC.generated.h"

UCLASS()
class STEALTHAGENTSIM_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Sprite that holds the vision cone
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vision")
	class UPaperSpriteComponent* VisionCone;

	// Sprite that holds the vision cone in dark conditions
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vision")
	class UPaperSpriteComponent* DarkVisionCone;

	// Can be called if there is a lighting change to alter NPC properties
	UFUNCTION(BlueprintCallable, Category = "Vision")
	virtual void DarkRoomLightingChange(bool bInDarkRoomUpdate);

	// Sets character movement speed to running or walking speed
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void SetCharacterRunning(bool bCharacterRunning);

protected:
	// True if in a dark room
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vision")
	bool bInDarkRoom;
	
	// Running speed
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Movement")
	float RunSpeed;

	// Walking speed
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Movement")
	float WalkSpeed;

};
