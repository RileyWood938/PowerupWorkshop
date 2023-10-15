// Fill out your copyright notice in the Description page of Project Settings.


#include "Charactor.h"

// Sets default values
ACharactor::ACharactor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharactor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharactor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float distanceToGround() {
	return 1.0f;
}


