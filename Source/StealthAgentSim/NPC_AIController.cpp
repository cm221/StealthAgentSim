// Fill out your copyright notice in the Description page of Project Settings.

#include "StealthAgentSim.h"
#include "NPC_AIController.h"
#include "Perception/PawnSensingComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

// Sets default values
ANPC_AIController::ANPC_AIController()
{
	// Create default subobjects for AI Perception & the sight sense
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("AI Perception Config"));
	
	// Initialise sight range & what it can detect
	SightConfig->SightRadius = SightFarRange;
	SightConfig->LoseSightRadius = SightFarRange;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	// Set dominant sense as sight and update the perception component
	AIPerception->SetDominantSense(SightConfig->GetSenseImplementation());
	AIPerception->ConfigureSense(*SightConfig);

}

// Called when there is a lighting change & alters sight radius
void ANPC_AIController::DarkRoomLightingChange(bool bInDarkRoomUpdate)
{
	// Update sight range based on room NPC is in
	if (bInDarkRoomUpdate == true)
	{
		SightConfig->SightRadius = SightShortRange;
		SightConfig->LoseSightRadius = SightShortRange;
	}
	else if (bInDarkRoomUpdate == false)
	{
		SightConfig->SightRadius = SightFarRange;
		SightConfig->LoseSightRadius = SightFarRange;
	}

	// Update Perception component with new sight radii
	AIPerception->ConfigureSense(*SightConfig);
}

