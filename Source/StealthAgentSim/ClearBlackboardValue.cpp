// Fill out your copyright notice in the Description page of Project Settings.

#include "StealthAgentSim.h"
#include "ClearBlackboardValue.h"
#include "BehaviorTree/BlackboardComponent.h"


// Called when task is executed
EBTNodeResult::Type UClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackBoardComp = OwnerComp.GetBlackboardComponent();

	BlackBoardComp->ClearValue(KeyToClear.SelectedKeyName);

	// Task succeeded
	return EBTNodeResult::Succeeded;
}





