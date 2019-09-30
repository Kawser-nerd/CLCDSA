using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1C
{
    class A
    {
        static void Main(string[] args)
        {
            int tests = int.Parse(Console.ReadLine());
            for (int t = 1; t <= tests; t++)
            {
                string[] s = Console.ReadLine().Split(' ');
                int r = int.Parse(s[0]), c = int.Parse(s[1]);
                StringBuilder[] b = new StringBuilder[r];
                for (int i = 0; i < r; i++)
                {
                    b[i] = new StringBuilder(Console.ReadLine());
                }
                bool imp = false;
                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                        if(b[i][j] == '#')
                    {
                        if (i + 1 < r && j + 1 < c && b[i + 1][j] == '#' && b[i + 1][j + 1] == '#' && b[i][j + 1] == '#')
                        {
                             b[i][j]= '/';
                             b[i+1][j] = '\\';
                             b[i][j+1] = '\\';
                             b[i+1][j+1] = '/';
                        }
                        else
                            imp = true;                        
                    }                
                }
                Console.WriteLine("Case #{0}:", t);

                if (imp)
                    Console.WriteLine("Impossible");
                else
                    for (int i = 0; i < r; i++)
                        Console.WriteLine(b[i].ToString());



                
            }
        }
    }
}
