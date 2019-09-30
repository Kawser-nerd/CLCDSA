using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace atcoder096_D
{
    class Program
    {
        static void Main(string[] args)
        {
            //???????
            int N = int.Parse(Console.ReadLine());

            //????1??????55???
            int[] sosu = new int[55];
            bool sosujdg = true;
            sosu[0] = 11;
            int cnt = 1;
            for (int i = 21; i < 55555; i = i + 10)
            {
                for (int j = 2; j < i; j++)
                {
                    if (i % j == 0)
                    {
                        sosujdg = false;
                        break;
                    }
                }
                if (sosujdg == true)
                {
                    sosu[cnt] = i;
                    cnt++;
                }
                sosujdg = true;
                if (cnt >= 55) break;
            }

            
            //??
            for(int i =0;i<N;i++)
            {
                Console.Write(sosu[i]);

                if (i == N - 1) break;
                Console.Write(" ");
            }
            Console.WriteLine();
            
        }
    }
}