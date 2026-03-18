// Fill out your copyright notice in the Description page of Project Settings.


#include "Assignment_Actor.h"
#include "Engine/Engine.h"

// Sets default values
AAssignment_Actor::AAssignment_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAssignment_Actor::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorLocation(FVector(0, 50, 0));
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("[Start Location] : %s"), *GetActorLocation().ToString()));
	UE_LOG(LogTemp, Warning, TEXT("[Start Location] : %s"), *GetActorLocation().ToString());

	for (int i = 0; i < 10; i++) 
	{
		float RandomX = FMath::RandRange(1, 100);
		float RandomY = FMath::RandRange(1, 100);
		float RandomZ = FMath::RandRange(1, 100);

		if (TriggerEvent_Actor()) 
		{
			Actor_Move(FVector(RandomX, RandomY, 0.f));//move
		}
		else 
		{
			Actor_Turn(FRotator(0.f, RandomZ, 0.f));
		}

	}
}

// Called every frame
void AAssignment_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
}

bool AAssignment_Actor::TriggerEvent_Actor()
{
	int32 RandomValue = FMath::RandRange(0, 1);

	if (RandomValue == 0) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void AAssignment_Actor::Actor_Move(const FVector& arrive)
{
	SetActorLocation(GetActorLocation() + arrive);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("Actor Move! : %s"), *GetActorLocation().ToString()));
		UE_LOG(LogTemp, Warning, TEXT("Actor Move! : %s"), *GetActorLocation().ToString());
	}
}

void AAssignment_Actor::Actor_Turn(const FRotator& turn)
{
	SetActorRotation(GetActorRotation() + turn);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("Actor Turn! : %s"), *GetActorRotation().ToString()));
		UE_LOG(LogTemp, Warning, TEXT("Actor Turn! : %s"), *GetActorRotation().ToString());
	}
}

