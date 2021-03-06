// main.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <cmath>


int main()
{
	std::cout <<
		"This is a program that determines the sides and angles of a triangle\n"
		"Make sure to remember that angle A is always opposite side a, angle B is opposite side b and so on!!!\n"
		"Choose the type of triangle you'd like to solve.\n"
		"for AAA enter 1\n"
		"for AAS enter 2\n"
		"for ASA enter 3\n"
		"for SAS enter 4\n"
		"for SSA enter 5\n"
		"for SSS enter 6\n" 
		<< std::endl;
	int type = 0;
	std::cin >> type;

	if (type > 6 || type < 1) {
		std::cout << "You have entered an invalid character" << std::endl;
		return 0;
	}
	else {

		double angleA;
		double angleB;
		double angleC;
		double sidea;
		double sideb;
		double sidec;
		const double pi{ 3.14159265359 };

		const double rad{ pi / 180 };
		double radAngleA;
		double radAngleB;
		double radAngleC;

		double bigAngle;
		const double deg{ 180 / pi };
		const int AAA{ 1 };
		const int AAS{ 2 };
		const int ASA{ 3 };
		const int SAS{ 4 };
		const int SSA{ 5 };
		const int SSS{ 6 };


		switch (type) {

		case AAA:


			std::cout << "You have selected AAA.  Please enter two of the angle measures in degrees" << '\n';
			std::cout << "Angle A: ";
			std::cin >> angleA;
			std::cout << "Angle B: ";
			std::cin >> angleB;
			if (angleA + angleB > 179) {
				std::cout << "This is unsolvable, check your inputs" << std::endl;
				break;
			}
			angleC = 180 - (angleA + angleB);
			std::cout << "Angle C: " << angleC << '\n';

			radAngleA = angleA * rad;
			radAngleB = angleB * rad;
			radAngleC = angleC * rad;

			if (angleA > angleB && angleA > angleC) {
				sidea = 1;
				sideb = ((sidea * sin(radAngleB)) / sin(radAngleA));
				sidec = ((sidea * sin(radAngleC)) / sin(radAngleA));
			}


			if (angleB > angleA && angleB > angleC) {
				sideb = 1;
				sidea = ((sideb * sin(radAngleA)) / sin(radAngleB));
				sidec = ((sidea * sin(radAngleC)) / sin(radAngleA));
			}

			if (angleC > angleB && angleC > angleA) {
				bigAngle = angleC;
				sidec = 1;
				sidea = ((sidec * sin(radAngleA)) / sin(radAngleC));
				sideb = ((sidea * sin(radAngleB)) / sin(radAngleA));
			}

			std::cout << "Proportional side a: " << sidea << '\n';
			std::cout << "Proportional side b: " << sideb << '\n';
			std::cout << "Proportional side c: " << sidec << std::endl;
			break;
	
			case AAS:
			std::cout << "You have selected AAS.  Please enter two angles in degrees and the measure of a side not between them" << '\n';
			std::cout << "Angle A: ";
			std::cin >> angleA;
			std::cout << "Angle C: ";
			std::cin >> angleC;
			std::cout << "Side c: ";
			std::cin >> sidec;
			if (angleA + angleC > 179) {
				std::cout << "This is unsolvable, check your inputs" << std::endl;
				break;
			}

			angleB = 180 - (angleA + angleC);

			radAngleA = angleA * rad;
			radAngleB = angleB * rad;
			radAngleC = angleC * rad;

			sideb = ((sidec * sin(radAngleB)) / sin(radAngleC));
			sidea = ((sidec * sin(radAngleA)) / sin(radAngleC));
			std::cout << "Angle C = " << angleC << '\n';
			std::cout << "Side b = " << sideb << '\n';
			std::cout << "Side a = " << sidea << '\n';

			break;

		case ASA:
			std::cout << "You have selected ASA.  Please enter angles in degrees and the measure of a side BETWEEN the angles" << '\n';
			std::cout << "Angle A: ";
			std::cin >> angleA;
			std::cout << "Side c: ";
			std::cin >> sidec;
			std::cout << "Angle B: ";
			std::cin >> angleB;
			if (angleA + angleB > 179) {
				std::cout << "This is unsolvable, check your inputs" << std::endl;
				break;
			}

			angleC = 180 - (angleA + angleB);
			radAngleA = angleA * rad;
			radAngleB = angleB * rad;
			radAngleC = angleC * rad;

			sidea = ((sidec * sin(radAngleA)) / sin(radAngleC));
			sideb = ((sidec * sin(radAngleB)) / sin(radAngleC));
			std::cout << "Angle C = " << angleC << '\n';
			std::cout << "Side a = " << sidea << '\n';
			std::cout << "Side b = " << sideb << '\n';
			break;

		case SAS:
			std::cout << "You have selected SAS. Please enter angles in degrees and the measure of a side" << '\n';
			std::cout << "Angle A: ";
			std::cin >> angleA;
			std::cout << "Side b: ";
			std::cin >> sideb;
			std::cout << "Side c: ";
			std::cin >> sidec;
			angleB = 1;

			if (angleA + angleB > 179) {
				std::cout << "This is unsolvable, check your inputs" << std::endl;
				break;
			}

			radAngleA = angleA * rad;

			sidea = sqrt((sideb * sideb) + (sidec * sidec) - 2 * sideb * sidec * cos(angleA));

			if ((sideb < sidec) || (sideb == sidec)) {

				angleB = (sin((sin(radAngleA) * sideb) / sidea));

				angleB *= deg;
				angleC = 180 - (angleB + angleA);
				std::cout << "Angle B = " << angleB << '\n';
				std::cout << "Angle C = " << angleC << '\n';
				std::cout << "side a = " << sidea;
				break;
			}

			if (sidec < sideb) {
				std::cout << radAngleA << '\n';
				angleC = (sin((sin(radAngleA) * sidec) / sidea));
				angleC *= deg;
				angleB = 180 - (angleC + angleA);

				std::cout << "Angle B = " << angleB << '\n';
				std::cout << "Angle C = " << angleC << '\n';
				std::cout << "Side a = " << sidea << '\n';
				break;
			}

		case  SSA:
			std::cout << "Please enter angle B in degrees and the measure of sides b and c" << '\n';
			std::cout << "Angle B: ";
			std::cin >> angleB;
			std::cout << "Side b: ";
			std::cin >> sideb;
			std::cout << "Side c: ";
			std::cin >> sidec;
			std::cout << angleB << std::endl;
			radAngleB = angleB * rad;
			angleC = (sin( (sin(radAngleB) * sidec) / sideb));
			angleC *= deg;
			angleA = 180 - (angleB + angleC);
			radAngleA = angleA * rad;
			sidea = (sideb * sin(radAngleA)) / sin(radAngleB);
			std::cout << "Angle A = " << angleA << '\n';
			std::cout << "Angle C = " << angleC << '\n';
			std::cout << "Side a = " << sidea << '\n';
			break;


		case SSS:
			std::cout << "Enter the measure of all 3 sides of the triangle" << '\n';
			std::cout << "Side a = ";
			std::cin >> sidea;
			std::cout << "Side b = ";
			std::cin >> sideb;
			std::cout << "Side c = ";
			std::cin >> sidec;

			angleC = acos((((sidea * sidea) + (sideb * sideb)) - (sidec * sidec)) / (2 * sidea * sideb));
			angleB = acos((((sidec * sidec) + (sidea * sidea)) - (sideb * sideb)) / (2 * sidec * sidea));
			angleC *= deg;
			angleB *= deg;
			angleA = 180 - (angleC + angleB);

			std::cout << "Angle A = " << angleA << '\n';
			std::cout << "Angle B = " << angleB << '\n';
			std::cout << "Angle C = " << angleC << std::endl;
			break;

		}
	}
	return 0;
}

