using System;
using System.Collections.Generic;
class Program
    {
    	static void Main(string[] args)
    	{
    		int n = int.Parse(Console.ReadLine());
            long[] x = new long[n], y = new long[n];
            for (int i=0; i<n; i++)
            {
                string[] pos = Console.ReadLine().Split(' ');
                x[i] = int.Parse(pos[0]);
                y[i] = int.Parse(pos[1]);
            }
            for (int i=0; i<n; i++)
            {
                long[] v1 = new long[] {x[i] - x[(i+1)%n], y[i] - y[(i+1)%n]};
                double max = 0, min = 0;
                for (int j=2; j<n; j++)
                {
                    long[] v2 = new long[] {x[i] - x[(i+j)%n], y[i] - y[(i+j)%n]};
                    double theta = Math.Acos((v1[0] * v2[0] + v1[1] * v2[1]) 
                    / (Math.Sqrt(v1[0] * v1[0] + v1[1] * v1[1]) * Math.Sqrt(v2[0] * v2[0] + v2[1] * v2[1])));
                    if (v1[0] * v2[1] - v1[1] * v2[0] < 0) theta *= -1;
                    //Console.Error.WriteLine(v1[0] + " " + v1[1] + " " + v2[0] + " " + v2[1] + " " + theta);
                    if (theta > max) max = theta;
                    if (theta < min) min = theta;
                }
                if (max - min > Math.PI * 0.99999) Console.WriteLine(0);
                else Console.WriteLine((Math.PI - max + min) / (2 * Math.PI));
            }
        }
    }
    //mcs Main.cs
    //mono Main.exe