/*Purpose: To display a 3D spinning Donut on terminal
 * Written By: D.Mohith Sai Kumar
 * Written On: 29/03/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

int main()
{
	float XA=0,ZB=0; //XA & ZB govern the angle to rotate around X & Z axes
	float x,y; //Loop Variables to calculate torus rotations
	int k; //Loop variable for printing the donut
	float z[80*22]; //Assuming the console size is 80 columns & 22 rows
	char b[80*22];
	printf("\x1b[2J"); //Clearing the console screen
	for(;;)
	{
		memset(b,32,80*22); //Fill the character buffer'b' with spaces(ASCII 32)
		memset(z,0,4*1760); //Reset Depth Buffer z
		for(float y = 0 ; y < 2 * M_PI ; y += 0.07)
		{
			for(float x =0; x < 2*M_PI ; x += 0.02)
			{
				float c = sin(x);
				float d = cos(y);
				float e = sin(XA);
				float f = sin(y);
				float g = cos(XA);
				float h = d + 2; //offset to keep donut infront of the viewer
				float D = 1/(c * h * e + f * g + 5); //Depth value calculation
				//Projecting to 2D
				float l = cos(x);
				float m = cos(ZB);
				float n = sin(ZB);
				float t = c * h * g - f * e;
				int X = (80/2) + 30 * D * (l * h * m - t * n);
				int Y = (22/2 + 1) + 15 * D * (l * h * n + t * m);
				int O = X + 80*Y;    //Mapy (X,Y) co-ordinate into 1 Dimnensional Buffer b[]
				//Calculating the brightness and shading the plot
				int L = 8 * ((f*e - c*d*g)*m - c*d*e - f*g - l*d*n);
				if(22 > Y && Y > 0 && X > 0 && 80 > X && D > z[O])
				{
					z[O] = D;
					b[O] = ".,-~:;=!*#$@"[L > 0 ? L : 0];
				}
			}
		}
		printf("\x1b[H"); //Moves the cursor back to the top left
		//Printing the donut
		for(k = 0; k < 1761 ; k++)
		{
			putchar(k % 80 ? b[k] :10);
			XA += 0.00004;
			ZB += 0.00002;
		}
		usleep(50000); //Control the Animation Speed
	}
	return 0;
}


