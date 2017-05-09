// Fill out your copyright notice in the Description page of Project Settings.

#include "StealthAgentSim.h"
#include "NPC.h"
#include "PaperSpriteComponent.h"
#include "NPC_AIController.h"


// Sets default values
ANPC::ANPC()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisionCone = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Vision Cone"));
	VisionCone->SetupAttachment(GetCapsuleComponent());
	VisionCone->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -87.0f), FRotator(0.0f, 90.0f, -90.0f));
	VisionCone->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	DarkVisionCone = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Dark Vision Cone"));
	DarkVisionCone->SetupAttachment(GetCapsuleComponent());
	DarkVisionCone->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -87.0f), FRotator(0.0f, 90.0f, -90.0f));
	DarkVisionCone->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	DarkVisionCone->SetVisibility(false);

	// Set the run & walk speeds
	RunSpeed = 500.0f;
	WalkSpeed = 300.0f;

	// Set character as initially running
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;

	// initialise the enemy as not being in a dark room
	bInDarkRoom = false;
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

// Called when there is a lighting change & alters the visibility of vision cones
void ANPC::DarkRoomLightingChange(bool bInDarkRoomUpdate)
{
	// Update if the NPC is in a dark room
	bInDarkRoom = bInDarkRoomUpdate;

	// Set the correct vision cone as visible
	if (bInDarkRoom == true)
	{
		VisionCone->SetVisibility(false);
		DarkVisionCone->SetVisibility(true);
	}
	else if (bInDarkRoom == false)
	{
		VisionCone->SetVisibility(true);
		DarkVisionCone->SetVisibility(false);
	}

	// Update AI controller with lighting change to adjust sight radius
	ANPC_AIController* AIController = Cast<ANPC_AIController>(GetController());
	if (AIController)
	{
		AIController->DarkRoomLightingChange(bInDarkRoom);
	}

}

void ANPC::SetCharacterRunning(bool bCharacterRunning)
{
	if (bCharacterRunning == true)
	{
		GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
	}
	else if (bCharacterRunning == false)
	{
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
}
