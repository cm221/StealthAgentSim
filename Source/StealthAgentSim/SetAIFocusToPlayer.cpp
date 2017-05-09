// Fill out your copyright notice in the Description page of Project Settings.

#include "StealthAgentSim.h"
#include "SetAIFocusToPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC_AIController.h"


// Called when task is executed
EBTNodeResult::Type USetAIFocusToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get blackboard component
	UBlackboardComponent* BlackBoardComp = OwnerComp.GetBlackboardComponent();

	// Get the AI controller 
	ANPC_AIController* NPCAI = Cast<ANPC_AIController>(OwnerComp.GetAIOwner());

	// Get the player blackboard key as an object
	AActor* PlayerActor = Cast<AActor>(BlackBoardComp->GetValueAsObject(PlayerKey.SelectedKeyName));

	// Check if player actor is set, if so set focus to player, otherwise clear focus
	if (PlayerActor)
	{
		NPCAI->SetFocus(PlayerActor);
	}
	else
	{
		NPCAI->ClearFocus(EAIFocusPriority::Gameplay);
	}

	// Task succeeded
	return EBTNodeResult::Succeeded;
}



