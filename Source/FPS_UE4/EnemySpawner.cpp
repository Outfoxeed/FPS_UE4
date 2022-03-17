// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UEnemySpawner::UEnemySpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	GLog->Log("Enemy Spawner");

	// Collect attached Actors
	GetOwner()->GetAttachedActors(SpawnPlaces);
	// TArray<AActor*> AttachedActors;
	// GLog->Log(FString::SanitizeFloat(AttachedActors.Num()));
	// for (AActor* AttachedActor : AttachedActors)
	// {
	// 	SpawnPlaces.Add(Cast<USceneComponent>(AttachedActor));
	// 	GLog->Log(AttachedActor->GetName());
	// }
}


// Called every frame
void UEnemySpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEnemySpawner::SpawnEnemies()
{
	for (const auto SpawnPlace : SpawnPlaces)
	{
		if(SpawnPlace == nullptr)
			continue;
		UClass* SpawnClass = &(enemiesClasses[0]);
		GLog->Log("Class");
		FVector SpawnLocation = SpawnPlace->GetActorLocation();
		GLog->Log("Location");
		FRotator SpawnRotator = FRotator::ZeroRotator;
		GLog->Log("Rotator");
		FActorSpawnParameters SpawnParameters;
		GLog->Log("SPawn params");

		GetWorld()->SpawnActor(SpawnClass, &SpawnLocation, &SpawnRotator, SpawnParameters);
		GLog->Log("SPawn");
	}
}
