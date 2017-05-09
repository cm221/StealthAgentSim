// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NPC.h"
#include "PatrollingEnemy.generated.h"

/**
 * 
 */
UCLASS()
class STEALTHAGENTSIM_API APatrollingEnemy : public ANPC
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	APatrollingEnemy();
	
	// Volume that will kill player if inside
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attack")
	class UBoxComponent* AttackVolume;

	// Funciton called when overlap has happened
	UFUNCTION(BlueprintImplementableEvent, Category = "Attack")
	void PlayerFound();

	// Overlap event with attack volume
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
