// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "SetAIFocusToPlayer.generated.h"

/**
 * 
 */
UCLASS()
class STEALTHAGENTSIM_API USetAIFocusToPlayer : public UBTTaskNode
{
	GENERATED_BODY()
	
	// Called when task is executed
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector PlayerKey;
};
