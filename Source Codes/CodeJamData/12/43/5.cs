using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    class CCCMOUNTAINS : AbstractSolver
    {
        void verify (int []x, int []height)
        {
            Console.WriteLine(String.Join(" ", height));

            for (int k = 0; k < x.Length; k++)
            {
                int best = -1;
                double degreMax = -1000000;
                for (int i = k + 1; i < height.Length; i++)
                {
                    double d = degree(k, i, height[i] - height[k]);
                    Console.WriteLine(k + " => " + i + " " + d);
                    if (d > degreMax) { degreMax = d; best = i; }
                }
                if (best + 1 != x[k]) throw new Exception("Z "+k + "najlepiej widac "+best+ 1);
            }

        }

        double degree(int i, int j, int hd)
        {
            return (double) hd / (j-i);
        }


        protected override object Solve(System.IO.StreamReader input)
        {
            int n = NextInt();

            var x = NextInts(n - 1);

            for (int i = 0; i < n - 1; i++)
            {
                if (x[i] <= i +1)
                    return "Impossible";
            }

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < x[i] - 1; j++)
                {

                    if (x[j] > x[i]) return "Impossible";
                }
            }



            Console.WriteLine("Dane: " + String.Join(", ", x));
            var heights = new int[n];

            int r = 0;


            int StartValue = 1000000000-1;

            heights[n - 1] = StartValue;

            

            int lastMax = n - 1;
            
                for (int i = 0; i < lastMax; i++)
                {
                    if (x[i] == lastMax + 1)
                    {
                        heights[i] = StartValue;
                        lastMax = i;
                        break;
                    }
                }

            
                r = 2;
                for (int z = 0; z < 10; z++)
                {

                    r *= 2;

                    for (int i = 0; i < n - 1; i++)
                    {
                        if (heights[i] == 0 && heights[x[i]-1] != 0)
                        {
                            heights[i] = heights[x[i]-1] - (x[i] - i + 1) * r;
                            r *= 2;
                        }
                    }
                }

                verify(x, heights);




            return String.Join(" ", heights);
           

        }


    }
}
