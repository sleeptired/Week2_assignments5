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
	float TotalDistance = 0.0f;
	int success_move = 0;
	SetActorLocation(FVector(0, 50, 0));
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("[Start Location] : %s"), *GetActorLocation().ToString()));
	UE_LOG(LogTemp, Warning, TEXT("[Start Location] : %s"), *GetActorLocation().ToString());
	int Totalcount = 0;
	for (; Totalcount < 10; Totalcount++)
	{
		float RandomX = FMath::RandRange(1, 100);
		float RandomY = FMath::RandRange(1, 100);
		float RandomZ = FMath::RandRange(1, 100);

		if (TriggerEvent_Actor()) 
		{
			if (TriggerEvent_Actor())
			{
				success_move++;
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("[Step %d]"), Totalcount));
				UE_LOG(LogTemp, Warning, TEXT("[Step %d]"), Totalcount);

				FVector Temp_ActorLocation = GetActorLocation();
				FVector Move_Location = GetActorLocation() + FVector(RandomX, RandomY, 0.f);
				TotalDistance += FVector::Dist(Temp_ActorLocation, Move_Location);

				Actor_Move(FVector(RandomX, RandomY, 0.f));//move
			}
			else 
			{
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("[Step %d]"), Totalcount));
				UE_LOG(LogTemp, Warning, TEXT("[Step %d]"), Totalcount);
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("Move Fail")));
				UE_LOG(LogTemp, Warning, TEXT("Move Fail"));
			}
		}
		else 
		{
			if (TriggerEvent_Actor()) 
			{
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("[Step %d]"), Totalcount));
				UE_LOG(LogTemp, Warning, TEXT("[Step %d]"), Totalcount);
				Actor_Turn(FRotator(0.f, RandomZ, 0.f));
			}
			else 
			{
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("[Step %d]"), Totalcount));
				UE_LOG(LogTemp, Warning, TEXT("[Step %d]"), Totalcount);
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("Turn Fail")));
				UE_LOG(LogTemp, Warning, TEXT("Turn Fail"));
			}
		}

	}

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("[Total Distance: %.2f]"), TotalDistance));
	UE_LOG(LogTemp, Warning, TEXT("[Total Distance: %.2f]"), TotalDistance);
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Purple, FString::Printf(TEXT("[Success move count: %d]"), success_move));
	UE_LOG(LogTemp, Warning, TEXT("[Success move count %d]"), success_move);
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
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString::Printf(TEXT("Actor Move! : %s"), *GetActorLocation().ToString()));
		UE_LOG(LogTemp, Warning, TEXT("Actor Move! : %s"), *GetActorLocation().ToString());
	}
}

void AAssignment_Actor::Actor_Turn(const FRotator& turn)
{
	SetActorRotation(GetActorRotation() + turn);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString::Printf(TEXT("Actor Turn! : %s"), *GetActorRotation().ToString()));
		UE_LOG(LogTemp, Warning, TEXT("Actor Turn! : %s"), *GetActorRotation().ToString());
	}
}

