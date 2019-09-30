// 
// File:   egg_drop.cpp
// Author: rsalmeidafl
//
// Created on 26 de Junho de 2008, 22:52
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

double tuffArea(double R, double y, double a, double b) {
    
    assert(a >= b);
    assert(a <= R);
    assert(b <= R);
    
    double R2 = R*R;
    double theta = acos(b/R);
    double phi = acos(a/R);
    
    assert (theta >= phi);
    
    double area = (R2/2)*(theta - phi) - (R2/4)*(sin(2*theta) - sin(2*phi)) - (a - b)*y;
    //assert(area >= 0);
    return area;
}

int main(int argc, char** argv) {
    
    int num_of_instances;
    int current_instance = 0;
        
    scanf("%d", &num_of_instances);
    
    while (current_instance++ < num_of_instances) {
        double f, R, t, r, g, R2;
        scanf("%lf %lf %lf %lf %lf", &f, &R, &t, &r, &g);
        
        t += f;
        R -= t;
        g -= 2*f;
        r += f;
        
        R2 = R*R;
                
        
        /* Compute "standard gap effective area" */
        double noHitArea = 0.0;
        
        if (g > 0 && R > 0) {

            double delta = 2*r + g;
            double bottom = r;
            double right = r;                    
            
            double stdarea = g*g;
            
            /* For each row */        
            while (bottom < R) {
                right = r;
                
                /* Are there any? */
                double top = bottom + g;
                double left = right + g;
                if (R > top) {
                    int number_of_standard_gaps = 1 + floor((sqrt(R*R - top*top) - (right + g))/delta);
                    noHitArea += number_of_standard_gaps*stdarea;
                    right += delta*number_of_standard_gaps;
                }
                
                /* Tuff gaps */
                
                while(bottom*bottom + right*right < R2) {

                    int toprightin = (bottom + g)*(bottom + g) + right*right <= R2;
                    int bottomleftin = bottom*bottom + (right + g)*(right + g) <= R2;
                    assert((bottom + g)*(bottom + g) + (right + g)*(right + g) > R2);                   
                    
                    double a, b, y, rect;
                    
                    /* First case: both corners out */
                    if (!toprightin && !bottomleftin) {
                        b = right;
                        a = sqrt(R2 - bottom*bottom);
                        assert(a >= b);
                        y = bottom;
                        rect = 0;
                    }
                    else if (toprightin && !bottomleftin) {
                        b = sqrt(R2 - (bottom + g)*(bottom + g));
                        a = sqrt(R2 - bottom*bottom);
                        assert(b >= right);
                        assert(a >= b);
                        y = bottom;
                        rect = (b - right)*g;
                    }
                    else if (!toprightin && bottomleftin) {
                        b = right;
                        a = right + g;
                        y = sqrt(R2 - a*a);
                        assert(y >= bottom);
                        rect = (y - bottom)*g;
                    }
                    else if (toprightin && bottomleftin) {
                        b = sqrt(R2 - (bottom + g)*(bottom + g));
                        a = right + g;
                        y = sqrt(R2 - a*a);
                        assert (a >= b);
                        assert(b >= right);
                        assert(y >= bottom);
                        rect = (a - b)*(y - bottom) + (b - right)*g;
                    }
                    
                    assert(rect >= 0);
                    noHitArea += rect;
                    noHitArea += tuffArea(R, y, a, b);
                    
                    right += delta;                    
                }

                bottom += delta;
            }
        }
        
        double totalArea = 3.141592653589793238462643*(R+t)*(R+t)/4;
        double probability = 1 - (noHitArea / totalArea);
        
        printf("Case #%d: %.6f\n", current_instance, probability);
    }    
    
    return (EXIT_SUCCESS);
}

