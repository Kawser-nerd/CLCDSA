using System;
using System.Collections.Generic;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var array = new List<int>();
            for (var i = 0; i < n; i++)
            {
                array.Add(int.Parse(Console.ReadLine()));
                if(i != 0 && array[0]<array[i])
                {
                    int tmp = array[0];
                    array[0] = array[i];
                    array[i] = tmp;
                }
            }
            int sum = array[0] / 2;
            for (var i = 1; i < n;i++)
            {
                sum += array[i];
            }
            Console.WriteLine(sum);
        }

    }
}