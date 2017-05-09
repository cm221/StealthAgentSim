// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRouteComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEALTHAGENTSIM_API UPatrolRouteComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*> GetWaypoints() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Waypoints")
	TArray<AActor*> WaypointTargetPoints;
	
};
