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

	FVector ActorLocation = GetActorLocation(); //Saved This Actor Location

	for (int i = 0; i < 10; i++) 
	{
		float RandomX = FMath::RandRange(1, 100);
		float RandomY = FMath::RandRange(1, 100);

		Actor_Move(FVector(RandomX, RandomY, 0.f));
	}
}

// Called every frame
void AAssignment_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

void AAssignment_Actor::Actor_Move(const FVector& arrive)
{
	SetActorLocation(GetActorLocation() += arrive);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("Actor Move : %s"), *GetActorLocation().ToString()));
	}
}

