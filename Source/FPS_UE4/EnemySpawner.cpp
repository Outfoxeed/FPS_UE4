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

	// Collect attached Actors
	GetOwner()->GetAttachedActors(SpawnPlaces);
}


// Called every frame
void UEnemySpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEnemySpawner::PrepareEnemiesSpawn()
{
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UEnemySpawner::SpawnEnemiesInstant, timeBeforeSpawn);
}

void UEnemySpawner::SpawnEnemiesInstant()
{
	for (const auto SpawnPlace : SpawnPlaces)
	{
		if(SpawnPlace == nullptr)
			continue;
		UClass* SpawnClass = &(enemiesClasses[0]);
		FVector SpawnLocation = SpawnPlace->GetActorLocation();
		FRotator SpawnRotator = FRotator::ZeroRotator;
		FActorSpawnParameters SpawnParameters;

		GetWorld()->SpawnActor(SpawnClass, &SpawnLocation, &SpawnRotator, SpawnParameters);
	}
	GLog->Log("Spawn");
}
