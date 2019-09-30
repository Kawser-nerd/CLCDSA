using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // ???????N?????
            int n = int.Parse(input);

            // ?????
            int[] array = new int[n];

            for(int i = 0; i < n; i++)
            {
                array[i] = int.Parse(Console.ReadLine());
            }

            // HashSet?????
            HashSet<int> hset = new HashSet<int>(array);

            // ???????
            int[] resultArray = new int[hset.Count];
            hset.CopyTo(resultArray, 0);

            // ?????
            Array.Sort(resultArray);

            // ???????
            Console.WriteLine(resultArray[resultArray.Count()-2]);
        }
    }
}