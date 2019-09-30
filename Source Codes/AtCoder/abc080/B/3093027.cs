using System;

namespace Sample101
{
    class Program
    {
        static int SumOfDigits(int n)
        {
            int sum = 0;
            while (n > 0)
            {
                sum += n % 10;
                n /= 10;
            }
            return sum;
        }
        static void Main(string[] args)
        {
            string result = "No";
            int N = int.Parse(Console.ReadLine());
            // N?????????
            // ???????
            // N?????????????????
            int sum = SumOfDigits(N);
            if (N % sum == 0)
            {
                result = "Yes";
            }

            Console.WriteLine(result);
        }
    }
}