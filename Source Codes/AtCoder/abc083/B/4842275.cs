using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC083_B
{
    class Program
    {
        static bool Check(int num, int a, int b)
        {
            int num_ = num;
            int sum = 0;

            while(num_ != 0)
            {
                sum += num_ % 10;
                num_ /= 10;
            }

            return (a <= sum && sum <= b);
        }

        static void Main(string[] args)
        {
            string[] strs = Console.ReadLine().Split(' ');
            int n = int.Parse(strs[0]);
            int a = int.Parse(strs[1]);
            int b = int.Parse(strs[2]);

            int sum = 0;

            for (int i = 1; i <= n; ++i)
            {
                if (Check(i, a, b))
                {
                    sum += i;
                }
            }

            Console.WriteLine($"{sum}");
        }
    }
}