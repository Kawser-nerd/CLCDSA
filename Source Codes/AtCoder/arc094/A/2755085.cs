using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            //_reads = new string[] { "200000", string.Join(" ", Enumerable.Repeat("1000000000", 200000)) };
            Console.WriteLine(Get());
        }

        static int Get()
        {
            int result = 0;
            var list = ReadLine().Split(' ').Select(int.Parse).ToList();
            list.Sort();
            int diff = list[1] - list[0];
            if (diff % 2 == 0)
            {
                return diff / 2 + list[2] - list[1];
            }
            else
            {
                return diff / 2 + list[2] - list[1] + 2;
            }
        }
}}