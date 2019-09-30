using System;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int? min = null;

            for(int i = 1; i < n; i++)
            {
                int y = n / i;
                int remain = n - i * y;

                int sum = Math.Abs(i - y) + remain;

                if (min == null)
                {
                    min = sum;
                }

                if(min > sum)
                {
                    min = sum;
                }


            }

            if(min == null)
            {
                min = 0;
            }
            Console.WriteLine(min);
        }
    }
}