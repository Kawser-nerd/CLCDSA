using System;
using System.Collections.Generic;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {

            // ??????????????

            // 1??
            long input1 = 0;
            input1 = long.Parse(Console.ReadLine());
            // 2??
            //string[] input2 = new string[] { "1", "2", "3", "4", "5", "6" };
            //string[] input2 = new string[] { "10", "-10" };
            string[] input2 = Console.ReadLine().Split(' ');
            //string[] input2 = new string[] { "1", "1", "1", "1", "1", "1" };
            //string[] input2 = new string[] { "6", "5", "4", "3", "2"};
            //string[] input2 = new string[] { "1", "0", "0", "0", "-1" };
            //string[] input2 = new string[] { "100000000000", "-100000000000" };

            List<long> resultList = new List<long>();

            long sum = 0;
            for (long i = 0; i < input2.Length; i++)
            {
                sum += long.Parse(input2[i]);
            }
            long senkou = 0;
            long koukou = 0;

            for (long i = 0; i < input2.Length -1; i++)
            {
                senkou += long.Parse(input2[i]);
                koukou = sum - senkou;
                long calcResult = senkou - koukou;
                if (calcResult < 0)
                {
                    calcResult = calcResult * -1;
                }
                resultList.Add(calcResult);
            }

            resultList.Sort();
            string ret = resultList[0].ToString();
            //??
            Console.WriteLine(ret);

        }

    }
}