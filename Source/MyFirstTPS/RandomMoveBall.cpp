// Fill out your copyright notice in the Description page of Project Settings.

#include "RandomMoveBall.h"

// Sets default values
ARandomMoveBall::ARandomMoveBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	xIncrease = true;
	yIncrease = true;
	zIncrease = true;
}

// Called when the game starts or when spawned
void ARandomMoveBall::BeginPlay()
{
	Super::BeginPlay();

	FVector&& pos = GetActorLocation();
	pos.X = -500.0;
	pos.Y = 0.0;
	pos.Z = 200.0;

	SetActorLocation( pos );
}

// Called every frame
void ARandomMoveBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector&& pos = GetActorLocation();

	if( xIncrease ){
		pos.X += 4.0;
		if( pos.X >= -300.0 ){
			xIncrease = false;
		}
	}
	else{
		pos.X -= 4.0;
		if( pos.X <= -700.0 ){
			xIncrease = true;
		}
	}

	if( yIncrease ){
		pos.Y += 2.0;
		if( pos.Y >= 100.0 ){
			yIncrease = false;
		}
	}
	else{
		pos.Y -= 2.0;
		if( pos.Y <= -100.0 ){
			yIncrease = true;
		}
	}

	if( zIncrease ){
		pos.Z += 3.0;
		if( pos.Z >= 330.0 ){
			zIncrease = false;
		}
	}
	else{
		pos.Z -= 3.0;
		if( pos.Z <= 130.0 ){
			zIncrease = true;
		}
	}

	SetActorLocation( pos );
}