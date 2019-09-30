using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC088_C
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a = new int[3];
            int[] b = new int[3];
            int[][] c = new int[3][];
            bool p = true;
            bool ans = false;
            for (int i = 0; i < 3; i++)
            {
                c[i] = Console.ReadLine().Split().Select(int.Parse).ToArray();
            }
            for (int i = 0; i <= 100; i++)
            {
                a[0] = i;
                for (int j = 0; j <= 100; j++)
                {
                    a[1] = j;
                    for (int k = 0; k <= 100; k++)
                    {
                        a[2] = k;
                        b = new int[3] { c[0][0] - a[0], c[0][1] - a[0], c[0][2] - a[0] };
                        p = true;
                        for (int l = 0; l < 3; l++)
                        {
                            
                            for (int m = 0; m < 3; m++)
                            {

                                if (c[l][m] != a[l] + b[m]) { p = false; }
                            }
                        }
                        ans |= p;
                    }
                }
            }
            Console.WriteLine(ans ? "Yes" : "No");
        }
    }
}