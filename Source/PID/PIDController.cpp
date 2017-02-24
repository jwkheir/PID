/*
Author: Jack Kheir
Date: 24/11/2016
*/
#include "PID.h"
#include "PIDController.h"

PIDController::PIDController(float pFactor, float iFactor, float dFactor)
{
	this->pFactor = pFactor;
	this->iFactor = iFactor;
	this->dFactor = dFactor;
	lastError = 0;
	ki = 0;
}

float PIDController::Update(float R, float Y, float time)
{
	float currentError = R - Y;
	UE_LOG(LogTemp, Warning, TEXT("Current Error: %f"), currentError);
	if (currentError != 0)
	{
		kp = currentError * pFactor;
		ki = iFactor + currentError * pFactor;
	}
	else
	{
		ki = 0;
		kp = 0;
	}

	if (currentError != 0)
	{
		kd = ((currentError - lastError)) * dFactor;
	}
	else
	{
		kd = 0;
	}
	lastError = currentError;
	return kp + ki + kd;
}

PIDController::~PIDController()
{
}
