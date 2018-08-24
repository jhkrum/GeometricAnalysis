/****************************************************************

 <br>
 <br> Subject:            Geometric Figures Analysis
 <br> Project:            Assignment002
 <br> Author:             Justin H. Krum
 <br> Creation Date:      September 24, 2017
 <br> Last Modification:  September 25, 2017

 ****************************************************************/


 /****************************************************************
 VAR NAME           TYPE       PURPOSE

 radius             float       To provide a radius to calculate area and perimeter of a circle
 baseRect           float       To provide a length of the base value to calculate area and perimeter of rectangle
 heightRect         float       To provide a height value to calculate area and perimeter of a rectangle
 baseTri            float       To provide a base value to calculate area and perimeter of a right triangle
 heightTri          float       To provide a height value to calculate area and perimeter of a right triangle
 boolean            int         To mimic the functionality of a boolean variable using macros to equal 0 and 1 (true and false)
 baseLength         float       To calculate in calcRectangle or calcRTriangle, depending on function
 heightLength       float       To calculate in calcRectangle or calcRTriangle, depending on function
 solutionCirc       float       To pass the value of perimeter or area back to main(), depending on boolean
 solutionRect       float       To pass the value of perimeter or area back to main(), depending on boolean
 solutionRTri       float       To pass the value of perimeter or area back to main(), depending on boolean
 PI                 float       To serve as a constant for the value of PI (3.14159)
 solutionCircle     float[]     To hold both the area and perimeter of the circle found with radius
 solutionRectangle  float[]     To hold both the area and perimeter of the rectangle found with baseRect and heightRect
 solutionRTriangle  float[]     To hold both the area and perimeter of the right triangle found with baseTri and heightTri
 sumArea            float       To hold the sum of the areas for the circle, rectangle, and right triangle
 avgArea            float       To hold the average of the areas for the circle, rectangle, and right triangle
 sumPerimeter       float       To hold the sum of the perimeters for the circle, rectangle, and right triangle
 avgPerimeter       float       To hold the average of the perimeters for the circle, rectangle, and right triangle

 ****************************************************************/

 /***************************************************************
                        ------TEST CASE-----
--INPUT--
Enter radius : 1

Enter rectangle base length : 1

Enter rectangle height length : 1

Enter triangle base length : 1

Enter triangle height length : 1

--OUTPUT--

        Area    Perim   AvgA    SumA    AvgP    SumP
Circ    3.14    6.28    1.55    4.64    4.57    13.70
Rect    1.00    4.00
RTri    0.50    3.41
 **************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>               //Included to allow for the use of:   float output = sqrt(float input)

#define true 1
#define false 0

float calcCircle(float radius, int boolean){        //Given radius, calculates Area and Circumference(Perimeter) of Circle

    float solutionCirc;                        //Provides easy format for transmitting solutions to main()
    const float PI = 3.14159;

    if(boolean == true)
        solutionCirc = PI* (radius * radius);      //solutionCircle holds Area of the Circle

    else if(boolean == false)
        solutionCirc = PI * (radius*2);            //solutionCircle holds Circumference of the Circle (Perimeter)

    return solutionCirc;
}


float calcRectangle(float baseLength, float heightLength, int boolean){  //Given base and height, calculates Area and Perimeter of Rectangle

    float solutionRect;                        //Provides easy format for transmitting solutions to main()

    if(boolean == true)
        solutionRect = baseLength * heightLength;      //Index 0 holds Area of the Rectangle

    else if(boolean == false)
        solutionRect = (baseLength * 2) + (heightLength*2);            //Index 1 holds Perimeter of the Rectangle

    return solutionRect;
}


float calcRTriangle(float baseLength, float heightLength, int boolean){  //Given base and height, calculates Area and Perimeter of Right Triangle

    float solutionRTri;                         //Provides easy format for transmitting solutions to main()

    if(boolean == true)
        solutionRTri = 0.5 * (baseLength * heightLength);      //solutionRTriangle holds Area of the Rectangle

    else if(boolean == false)
        solutionRTri = sqrt((baseLength * baseLength) + (heightLength * heightLength)) + baseLength + heightLength;            //solutionRTriangle holds Perimeter of the Rectangle

    return solutionRTri;
}


/****************************************************************
 * Main function to start the application.
 *
 * @return	int		program exit status
 */

int main(){

    float radius, baseRect, heightRect, baseTri, heightTri;

    printf("Enter radius : ");      //Input of radius value for a circle
    scanf("%f", &radius);

    printf("\nEnter rectangle base length : ");     //Input of baseLength for a rectangle
    scanf("%f", &baseRect);
    printf("\nEnter rectangle height length : ");   //Input of heightLength for a rectangle
    scanf("%f", &heightRect);

    printf("\nEnter triangle base length : ");      //Input of baseLength for a triangle
    scanf("%f", &baseTri);
    printf("\nEnter triangle height length : ");    //Input of heightLength for a triangle
    scanf("%f", &heightTri);

    float solutionCircle[2] = {calcCircle(radius, true),
                               calcCircle(radius, false)};

    //Area is held in solutionCircle[0]
    //Circumference is held in solutionCircle[1]


    float solutionRectangle[2] = {calcRectangle(baseRect, heightRect, true),
                                  calcRectangle(baseRect, heightRect, false)};

    //Area is held in solutionRectangle[0]
    //Perimeter is held in solutionRectangle[1]

    float solutionRTriangle[2] = {calcRTriangle(baseTri, heightTri, true),
                                  calcRTriangle(baseTri, heightTri, false)};

    //Area is held in solutionRTriangle[0]
    //Perimeter is held in solutionRTriangle[1]

    float sumArea = (solutionCircle[0] + solutionRectangle[0] + solutionRTriangle[0]),
          sumPerimeter = (solutionCircle[1] + solutionRectangle[1] + solutionRTriangle[1]),
          averageArea = sumArea/3,
          averagePerimeter = sumPerimeter/3;

    //sumArea holds the sum of the Area of all 3 geometric figures
    //sumPerimeter holds the sum of the Perimeter of all 3 geometric figures
    //averageArea holds the average Area for all 3 geometric figures
    //averagePerimeter holds the average Perimeter for all 3 geometric figures

    printf("\n\n\tArea\tPerim\tAvgA\tSumA\tAvgP\tSumP");


    for(int a = 0; a < 3; a++){     //Creates table setup for displaying values of geometric figures
        if(a==0){
            printf("\nCirc");
            for(int b = 0; b < 6; b++){     //Outputs values for circle and all average values
                if(b == 0 || b == 1){
                    printf("\t%.2f", solutionCircle[b]);
                }
                else if(b == 2) printf("\t%.2f", averageArea);      //Outputs averageArea
                else if(b == 3) printf("\t%.2f", sumArea);          //Outputs sumArea
                else if(b == 4) printf("\t%.2f", averagePerimeter); //Outputs averagePerimeter
                else if(b == 5) printf("\t%.2f", sumPerimeter);     //Outputs sumPerimeter
            }
        }
        else if(a==1){                      //Outputs values for rectangle
            printf("\nRect");
            for(int b = 0; b < 2; b++){
                printf("\t%.2f", solutionRectangle[b]);
            }
        }
        else if(a==2){                      //Outputs values for right triangle
            printf("\nRTri");
            for(int b = 0; b < 2; b++){
                printf("\t%.2f", solutionRTriangle[b]);
            }
        }
    }

    return 0;
}
