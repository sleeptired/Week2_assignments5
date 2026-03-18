// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Assignment_Actor.generated.h"

UCLASS()
class WEEK2_ASSIGNMENTS05_API AAssignment_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAssignment_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool TriggerEvent_Actor();
	void Actor_Move(const FVector& arrive);
	void Actor_Turn(const FRotator& turn);

};
