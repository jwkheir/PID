/*
Author: Jack Kheir
Date: 24/11/2016
*/
#pragma once

/**
 * 
 */
class PID_API PIDController
{
public:
	UPROPERTY(EditAnywhere)
	float pFactor, iFactor, dFactor; //Propotional, Integral, Derivative Factors
private:
	float kp, ki, kd; // Constants
	float lastError; // Used in the kd equation to determine 
	float integralActiveZone = 50; // Integral maximum value
public:
	PIDController(float pFactor, float iFactor, float dFactor);
	~PIDController();
	float Update(float R, float Y, float time);
};
