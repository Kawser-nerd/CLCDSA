using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace happy_numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.SetIn(new StreamReader(".\\input.txt"));
            //Console.SetOut(new StreamWriter(".\\output.txt"));

            int Cases = int.Parse(Console.ReadLine());

            for (int c = 1; c <= Cases; c++)
            {
                string a = Console.ReadLine();
                string[] b = a.Split(' ');
                int[] bases = new int[b.Length];

                for (int i = 0; i < b.Length; i++)
                {
                    bases[i] = Convert.ToInt32(b[i]);
                }

                int bb=0;
                int n=2;
                int level = 0;
                bool found = false;

                while (!found)
                {
                    found = true;
                    for (bb = 0; bb < bases.Length; bb++)
                    {
                        level = 0;
                        if (!ishappy(n, bases[bb],ref level))
                        {
                            found = false;
                            break;
                        }
                    }
                    n++;
                }


                n--;

                // решение
               // ishappy(82, 10);

                
                Console.Write("Case #" + c + ": ");
                Console.WriteLine(n);
            }

        }


        static bool ishappy(int a, int bas, ref int level)
        {
            if (level > 11)
                return false;
            int digit;
            int sqsum=0;
            while (a > 0)
            {
                digit = a % bas;
                sqsum += digit * digit;
                a = (a - digit)/bas;
            };

            level++;
            if (sqsum != 1)
                return ishappy(sqsum, bas, ref level);
            else
                return true;
        }
    }
}
