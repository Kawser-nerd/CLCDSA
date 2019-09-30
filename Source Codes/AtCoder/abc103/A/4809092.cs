using System;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            MainStream();
        }
        static void MainStream()
        {
            int cost = 0;
            string[] ?tmp = Console.ReadLine().Split(' ');
            int[] a_list = tmp.Select(s => int.Parse(s)).ToArray();
            Array.Sort(a_list);

            int before = a_list[0];

            for (int i=1; i<a_list.Length; i++)
            {
                cost += (a_list[i] - before);
                before = a_list[i];
            }

            Console.WriteLine(cost);
        }



    }
}