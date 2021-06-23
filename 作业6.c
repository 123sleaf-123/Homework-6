#include <stdio.h>
#include <math.h>
float norm(float age);
float pcdif(float actual,float base);
void showit(float normht,float perdif);

float norm(float age){
	const float MINAGE = 6.0;
	float agedif, avght;
	
	agedif = age - MINAGE;
	avght = -0.25 * pow(agedif,2) + 3.5 * agedif + 45.0;
	return (avght);
}

float pcdif(float actual,float base){
	return (actual - base) / base * 100.0;
}

void showit(float normht,float perdif){
	printf("\nThe average height in inches is: %6.2f",normht);
	printf("\nThe actual height deviates form the norm by %6.2f",perdif);
}

int main (void)
{
	int years, months;
	float height, normht;
	float age, perdif;
	
	do{
		printf("\nHow many years old is this child? ");
		scanf("%d",&years);
		if (years < 6){
			printf("Condition does not fit.\n");
			continue;
		}
		else
			break;
	}while(1);
	printf("How many months since the child's birth? ");
	scanf("%d",&months);
	age = years + months/12.0;
	printf("Enter the child's height(in inches): ");
	scanf("%f",&height);
	
	normht = norm(age);
	perdif = pcdif(height,normht);
	
	showit(normht,perdif);
	
	return 0;
}
