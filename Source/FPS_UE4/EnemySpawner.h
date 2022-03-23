// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemySpawner.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_UE4_API UEnemySpawner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemySpawner();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> SpawnPlaces;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> enemiesClasses;

	// UPROPERTY(EditAnywhere)
	// float timeBeforeSpawn = 2.5f;

public:
	// UFUNCTION(BlueprintCallable)
	// void PrepareEnemiesSpawn();
	
	UFUNCTION(BlueprintCallable)
	void SpawnEnemiesInstant();

};
