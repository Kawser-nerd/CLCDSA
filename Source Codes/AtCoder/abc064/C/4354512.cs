using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{



    class Program
    {

        const int Gray = 1;
        const int Brown = 2;
        const int Green = 3;
        const int LightBlue = 4;
        const int Blue = 5;
        const int Yellow = 6;
        const int Orange = 7;
        const int Red = 8;
        const int Brack = 9;

        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            int[] data = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            var dic = new Dictionary<int, bool>();

            for (int i = 1; i <= 9; i++)
            {
                dic[i] = false;
            }

            int color = 0;
            int cnt_brack = 0;
            for (int i = 0; i < N; i++)
            {
                color = data[i];
                
                if (1 <= color && color <= 399)
                {
                    color = Gray;
                }
                else if (color <= 799)
                {
                    color = Brown;
                }
                else if (color <= 1199)
                {
                    color = Green;
                }
                else if (color <= 1599)
                {
                    color = LightBlue;
                }
                else if (color <= 1999)
                {
                    color = Blue;
                }
                else if (color <= 2399)
                {
                    color = Yellow;
                }
                else if (color <= 2799)
                {
                    color = Orange;
                }
                else if (color <= 3199)
                {
                    color = Red;
                }
                else if (color >= 3200)
                {
                    dic[color] = true;
                    color = Brack;
                    cnt_brack++;
                }
                
                dic[color] = true;

            }

            
            int min = 0;
            int max = 0;

            for (int i = 1; i < 9; i++)
            {
                if (dic[i])
                {
                    min++;
                }
            }

            max = min;

            if (min == 0 && cnt_brack >= 1)
            {
                min++;
            }

            max += cnt_brack;

            Console.WriteLine($"{min} {max}");

        }
    }
}