// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "NPC_AIController.generated.h"

/**
*
*/
UCLASS()
class STEALTHAGENTSIM_API ANPC_AIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC_AIController();

	// AI sensing component used for vision
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vision")
	class UAIPerceptionComponent* AIPerception;

	// AI sensing component used for vision
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vision")
	class UAISenseConfig_Sight* SightConfig;

	// Can be called if there is a lighting change to alter NPC AI properties
	UFUNCTION(BlueprintCallable, Category = "Vision")
	virtual void DarkRoomLightingChange(bool bInDarkRoomUpdate);

	// Long sight range in light
	UPROPERTY(EditDefaultsOnly, Category = "Vision")
	float SightFarRange = 600.0f;

	// Short sight range in dark
	UPROPERTY(EditDefaultsOnly, Category = "Vision")
	float SightShortRange = 300.0f;

};
