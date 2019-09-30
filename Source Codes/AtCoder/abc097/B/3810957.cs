using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace atcoder097_B
{
    class Program
    {
        static void Main(string[] args)
        {
            //???????
            int X = int.Parse(Console.ReadLine());

            //??????????
            int result = 0; ;

            //1000??????????
            int[] Beki = new int[350];
            int cnt = 0;
            for (int i = 1; i < 33; i++)
            {
                for (int j = 2; j < 9; j++)
                {
                    Beki[cnt] = (int)Math.Pow(i, j);
                    cnt++;
                }
            }

            //X?????????????
            for (int i = X; i > 0; i--)
            {
                for (int j = 0; j < 350; j++)
                {
                    if (i == Beki[j])
                    {
                        result = Beki[j];
                        goto last;
                    }
                }
            }

            last:;
            Console.WriteLine(result);
        }
    }
}