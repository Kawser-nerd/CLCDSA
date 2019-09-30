using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            int impN = int.Parse(Console.ReadLine());
            int[] mochis = new int[impN];
            for (int i = 0; i < impN; i++)
            {
                mochis[i] = int.Parse(Console.ReadLine());
            }
            Array.Sort(mochis);
            int[] mochisD= mochis.Distinct().ToArray();
            Console.Write(mochisD.Length);


            //System.Threading.Thread.Sleep(1000);
        }
    }
}