/*
Author: Jack Kheir
Date: 24/11/2016
*/
#include "PID.h"
#include "Cube.h"


// Sets default values
ACube::ACube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACube::BeginPlay()
{
	Super::BeginPlay();
	pid = new PIDController(kp, ki, kd);
}

// Called every frame
void ACube::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//Rotation
	rot = GetActorRotation();
	rotation = pid->Update(finalRot, rot.Roll, DeltaTime);
	rot.Roll += rotation;
	SetActorRotation(rot);
}

