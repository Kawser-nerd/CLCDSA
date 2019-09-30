using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_016_B
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            char[,] a = new char[n,9];
            int x = 0;
            for (int i = 0; i < n; i++)
            {
                string sdcardingnow = Console.ReadLine();
                for (int k = 0; k < 9; k++)
                {
                 a[i, k] = sdcardingnow[k];
                    if (sdcardingnow[k] == 'x') { x++; }
                }
            }
            for (int i = 0; i < 9; i++)
            {
                int kakoren = 0;
                int renzoku = 0;
                for (int k = 0; k < n; k++)
                {
                    kakoren = renzoku;
                    if (a[k, i] == 'o') { renzoku++; }
                    else { renzoku = 0; }
                    if (renzoku == 0 && kakoren > 0)
                    {
                        x++;
                    }
                
                }    if (renzoku>0) { x++; }
                
            }Console.WriteLine(x);
            Console.ReadLine();
        }
    }
}