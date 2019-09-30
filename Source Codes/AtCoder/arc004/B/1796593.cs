using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ForRecords
{
    class Program
    {
        static void Main(string[] args)
        {
            int length = int.Parse(Console.ReadLine());
            int[] valuue = new int[length];
            for (int i = 0; i < valuue.Length; i++)
            {
                valuue[i] = int.Parse(Console.ReadLine());
            }
            Console.WriteLine(valuue.Sum());
            Console.WriteLine(Math.Max(0, valuue.Max() - (valuue.Sum() - valuue.Max())));
        }
    }
}