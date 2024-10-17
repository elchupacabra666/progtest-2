#include <stdio.h>
#include <math.h>


int GetInputs(double points[3][2]) {
	char letter = 65;
	for (int i = 0; i < 3; i++, letter++) {

		printf("Bod %c:\n", letter);
		if (scanf("%lf %lf", &points[i][0], &points[i][1]) != 2) {
			printf("Nespravny vstup.\n");
			return 1;
		}
	}
	return 0;
}

void MakeLine(double points[3][2], double line[3]) {
	line[0] = points[0][1] - points[1][1];				/* a = y1 - y2 			*/
	line[1] = - (points[0][0] - points[1][0]);			/* b = -(x1 - x2) 		*/
	line[2] = - (line[0] * points[0][0] + line[1] * points[0][1]);	/* c = - (a * x1 + b * y1)	*/
}

int IsEqual(double a, double b)
{
	return (abs(a-b) <= 0.001 * (abs(a) + abs(b)));
}

int PointsEqual(double points[3][2]) {
	if (	(points[0][0] == points[1][0] && points[0][1] == points[1][1]) ||
		(points[0][0] == points[2][0] && points[0][1] == points[2][1]) ||
		(points[1][0] == points[2][0] && points[1][1] == points[2][1]) ) {
		return 1;
		}
	return 0;
}


int IsOnLine(double points[3][2], double line[3]) {
	double a3, b3, c;
	a3 = line[0] * points[2][0];
	b3 = line[1] * points[2][1];
	c = line[2];
	if (IsEqual(a3 + b3, -c) == 1) {						/* a * x3 + b * y3 + c = 0	*/	
		return 1;
	}
	else {	
		return 0;
	}
}

char FindMid(double a, double b, double c, double points[3][2]) {
	if ((a < b && a > c) || (a < c && a > b)) {	
		return 'A';
	}
	if ((b < c && b > a) || (b < a && b > c)) {	
		return 'B';
	}
	if ((c < a && c > b) || (c < b && c > a)) {
		return 'C';
	}
	if (a == b && b == c){
		return FindMid(points[0][1], points[1][1], points[2][1], points);
	}
	return a;
}

int main(void) {
	double points[3][2], line[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= 1; j++) {
			points[i][j] = 0;
		}
	}
	
	if (GetInputs(points) == 1) {
		return 1;
	} 
	
	if (PointsEqual(points) == 1) {
		printf("Nektere body splyvaji.\n");
		return 0;
	}
	
	MakeLine(points, line);
	
	if (IsOnLine(points, line) == 0) {
		printf("Body nelezi na jedne primce.\n");
		return 0;	
	}
	
	printf("Body lezi na jedne primce.\n");
	
	printf("Prostredni je bod %c.\n", FindMid(points[0][0], points[1][0], points[2][0], points));
	
	return 0;
}

