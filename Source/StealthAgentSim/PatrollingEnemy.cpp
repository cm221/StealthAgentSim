// Fill out your copyright notice in the Description page of Project Settings.

#include "StealthAgentSim.h"
#include "PatrollingEnemy.h"
#include "PlayerCharacter.h"


// Sets default values
APatrollingEnemy::APatrollingEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttackVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Attack Volume"));
	AttackVolume->SetupAttachment(GetCapsuleComponent());
	AttackVolume->RelativeLocation = FVector(36.0f, 0.0f, 0.0f); // Position the attack volume
	AttackVolume->SetBoxExtent(FVector(60.0f, 30.0f, 80.f), true);
	AttackVolume->bGenerateOverlapEvents = true;
	AttackVolume->OnComponentBeginOverlap.AddDynamic(this, &APatrollingEnemy::OnOverlapBegin);

	// Set character as initially walking
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void APatrollingEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && Cast<APlayerCharacter>(OtherActor) && OtherComp == OtherActor->GetRootComponent())
	{
		// Blueprint function called when overlapped with player
		PlayerFound();
	}
	return;
}



