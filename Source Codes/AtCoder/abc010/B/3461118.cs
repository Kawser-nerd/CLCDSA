using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();

            int answer = 0;
            foreach(int tmp in a)
            {
                int remain = tmp % 6;

                if(remain == 0)
                {
                    answer += 3;
                }
                else if(remain == 5)
                {
                    answer += 2;
                }
                else if(remain == 2 || remain == 4)
                {
                    answer += 1;
                }
            }

            Console.WriteLine(answer);
        }
    }
}