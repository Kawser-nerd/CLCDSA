using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        string[] s = Console.ReadLine().Split(' ');
        int a = int.Parse(s[0]);
        int b = int.Parse(s[1]);
        int c = int.Parse(s[2]);
        int d = int.Parse(s[3]);
        int e = int.Parse(s[4]);
        int f = int.Parse(s[5]);

        double ans_concentration = 0.0;
        double max_concentration = 100.0 * ((double)e / (e + 100.0));
        int ans_sugar = 0;
        int ans_total = 100 * a;

        for (int i = 0; 100 * a * i <= f; i++)
        {
            for(int j = 0; 100 * b * j <= f; j++)
            {
                for(int k = 0; c * k <= f; k++)
                {
                    for(int l = 0; d * l <= f; l++)
                    {
                        int water = 100 * a * i + 100 * b * j;
                        int sugar = c * k + d * l;
                        int total = water + sugar;

                        if(i == 0 && j == 0)
                        {
                            continue;
                        }

                        if(total <= f && total >= 100 * a)
                        {
                            double concentration = 100.0 * (double)sugar / (double)total;
                            if (concentration <= (max_concentration + 1e-7) && concentration >= ans_concentration)
                            {
                                ans_concentration = concentration;
                                ans_sugar = sugar;
                                ans_total = total;
                            }
                        }
                    }
                }
            }
        }
        Console.WriteLine(ans_total + " " + ans_sugar);
    }
}