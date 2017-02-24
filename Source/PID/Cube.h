/*
Author: Jack Kheir
Date: 24/11/2016
*/
#pragma once

#include "PIDController.h"
#include "GameFramework/Actor.h"
#include "Cube.generated.h"

UCLASS()
class PID_API ACube : public AActor
{
	GENERATED_BODY()
public:
	PIDController *pid;
	
	UPROPERTY(EditAnywhere, Category = PID)
	float finalRot;//PID Process Value i.e. Wanted/Final Rotation

	//PID Constants 
	UPROPERTY(EditAnywhere, Category = PID)
	float kp;
	UPROPERTY(EditAnywhere, Category = PID)
	float ki;
	UPROPERTY(EditAnywhere, Category = PID)
	float kd;
private:
	FRotator rot;//Rotation Struct
	float rotation;//Rotation Speed returned from PID Controller
public:	
	ACube();
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;
};
