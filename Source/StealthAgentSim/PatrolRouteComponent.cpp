// Fill out your copyright notice in the Description page of Project Settings.

#include "StealthAgentSim.h"
#include "PatrolRouteComponent.h"



TArray<AActor*> UPatrolRouteComponent::GetWaypoints() const
{
	return WaypointTargetPoints;
}