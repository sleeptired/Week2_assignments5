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

	if (GEngine) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Text"));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("Actor : %s"), *GetName()));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("Actor : %s"), *ActorLocation.ToString()));
	}
	
}

// Called every frame
void AAssignment_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


