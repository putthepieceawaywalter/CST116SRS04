// CST116SRS04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>



int main()
{

	//step one prompt user for what triangle config they would like to use
	//( )


	//step two enter the values for that triangle
	//( )
	//step 3 note all measurements.  In the case of AAA note that the measurements are only proportional
	//( )
		//step 3a If the triangle is of type AAA only prompt for two angles and calculate the third
		//( )


	//step 4 All angles are to be entered and listed in degrees.  The trig functions in C++ only work in radians 
	//( )	
		//step 4a. You'll have to convert the inputs from degrees to radians and the output from radians to degrees
		//( )


	//step 5 If the solution is not solveable it must output "Unsolvable"
	//( )


	// Does ch. 7 cover using methods?  That would probably be the easiest way to make readable code

	int type = 0;
	double angleA;
	double angleB;
	double angleC;
	double sidea;
	double sideb;
	double sidec;



	double rad = 3.14159265359 / 180;
	double radAngleA;
	double radAngleB;
	double radAngleC;

	double deg = 180 / 3.14159265359;

	std::cout << "This is a program that determine sides and angles of a triangle" << '\n';
	std::cout << "Make sure to remember that angle A is always opposite side a, angle B is opposite side b and so on!!!" << '\n';
	std::cout << "Choose the type of triangle you'd like to solve." << '\n';
	std::cout << "for AAA enter 1" << '\n';
	std::cout << "for AAS enter 2" << '\n';
	std::cout << "for ASA enter 3" << '\n';
	std::cout << "for SAS enter 4" << '\n';
	std::cout << "for SSS enter 5" << '\n';

	std::cin >> type;

	if (type > 5 || type < 1) {
		std::cout << "You have entered an invalid character" << std::endl;
		return 0;
	}
	else {
		switch (type) {
		

		//this is for AAA
		case 1:
			std::cout << "You have selected AAA.  Please enter two of the angle measures in degrees" << '\n';
			std::cin >> angleA;
			std::cin >> angleB;
			angleC = 180 - (angleA + angleB);
			std::cout << "Angle A = " << angleA << " Angle B in rads is  = " << angleB << " Angle C is " << angleC << std::endl;

			break;
		
			
		//this is for AAS
		case 2:

			//CHANGE INPUTS TO MATCH MATHWAY.COM
			std::cout << "You have selected AAS.  Please enter two angles in degrees and the measure of a side not between them" << '\n';
			std::cout << "Angle A: ";
			std::cin >> angleA;
			std::cout << '\n' << "Angle B: ";
			std::cin >> angleB;
			std::cout << '\n' << "Side a: ";
			std::cin >> sidea;
			angleC = 180 - (angleA + angleB);

			radAngleA = angleA * rad;
			radAngleB = angleB * rad;
			radAngleC = angleC * rad;

			sideb = ((sidea * sin(radAngleB)) / sin(radAngleA));
			sidec = ((sidea * sin(radAngleC)) / sin(radAngleA));
			std::cout << "Angle C = " << angleC << '\n';
			std::cout << "Side b = " << sideb << '\n';
			std::cout << "Side c = " << sidec << '\n';
			
			break;
		
			
			
		//This is for ASA
		case 3:
			std::cout << "You have selected ASA.  Please enter angles in degrees and the measure of a side BETWEEN the angles" << '\n';
			std::cout << "Angle A: ";
			std::cin >> angleA;
			std::cout << '\n' << "Side c: ";
			std::cin >> sidec;
			std::cout << '\n' << "Angle B: ";
			std::cin >> angleB;

			angleC = 180 - (angleA + angleB);

			radAngleA = angleA * rad;
			radAngleB = angleB * rad;
			radAngleC = angleC * rad;

			sidea = ((sidec * sin(radAngleA)) / sin(radAngleC));
			sideb = ((sidec * sin(radAngleB)) / sin(radAngleC));
			std::cout << "Angle C = " << angleC << '\n';
			std::cout << "Side a = " << sidea << '\n';
			std::cout << "Side b = " << sideb << '\n';

		//This is for SAS
		case 4:


			std::cout << "You have selected SAS. Please enter angles in degrees and the measure of a side" << '\n';
			std::cout << "Angle A: ";
			std::cin >> angleA;
			std::cout << '\n' << "Side b: ";
			std::cin >> sideb;
			std::cout << '\n' << "Side c: ";
			std::cin >> sidec;

			radAngleA = angleA * rad;


			sidea = sqrt( (sideb * sideb) + (sidec * sidec) - 2 * sideb * sidec * cos(angleA));
			std::cout << "side a " << sidea << std::endl;
			if (sideb < sidec) {
				//perform inverse law of sines to solve for angle B
				double angleB = (1/sin((sin(radAngleA) * sideb) / sidea));
				angleC = 180 - (angleB + angleA);


				//now do the law of sines
			}

			if (sidec < sideb) {

				std::cout << "no test for this yet ";
				//perform inverse law of sines to solve for angle C
			}
			
		}

	}





    return 0;
}

