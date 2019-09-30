using System;
using System.Collections.Generic;
using System.Linq;

namespace Energy_Drink_Collector
{
    class Program
    {
        static void Main(string[] args)
        {
            var nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var dic = new SortedList<int, int>();
            for (int i = 0; i < nm[0]; i++)
            {
                var input = Console.ReadLine().Split().Select(int.Parse).ToArray();
                if (dic.ContainsKey(input[0]))
                {
                    dic[input[0]] += input[1];
                }
                else { dic[input[0]] = input[1]; }
            }

            var result = 0L;
            int index = 0;
            var key = dic.Keys[index];
            while (0 != nm[1]--)
            {
                if (0 == dic[key]) { key = dic.Keys[++index]; }

                result += key;
                dic[key]--;
            }
            Console.WriteLine(result);
        }
    }
}