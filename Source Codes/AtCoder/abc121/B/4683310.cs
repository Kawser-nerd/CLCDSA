using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ACprac
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] num1 = Console.ReadLine().Split(' ');
            int N = int.Parse(num1[0]);
            int M = int.Parse(num1[1]);
            int C = int.Parse(num1[2]);

            int[] B = new int[M];

            int count = 0;

            for (int i = 0; i < N+1; i++)
            {
                string[] num2 = Console.ReadLine().Split(' ');
                int tmp = 0;

                for (int k = 0; k < M; k++)
                {
                    if(i == 0)
                    {
                        B[k] = int.Parse(num2[k]);
                    }
                    else
                    {
                        tmp = tmp + (int.Parse(num2[k])*B[k]);
                    }
                }

                if(i > 0)
                {
                    if(tmp + C > 0)
                    {
                        count++;
                    }
                }

            }

            Console.WriteLine(count);

        }
    }
}