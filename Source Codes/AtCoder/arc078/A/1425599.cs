using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ProCon
{

    class Program
    {
        static long[] Nums;
        static void Main(string[] args)
        {
            Console.ReadLine();
            string[] input = Console.ReadLine().Split(' ');
            Nums = new long[input.Count()];
            int i = 0;
            long All = 0;
            foreach ( string str in input)
            {
                Nums[i] = long.Parse(str);
                All += Nums[i];
                ++i;
            }
            long Sum1 = 0;
            long Sum2 = All;
            long LastResult = long.MaxValue;
            for(int j = 0; j < input.Count() - 1; ++j)
            {
                Sum1 += Nums[j];
                Sum2 -= Nums[j];
                if(LastResult > Math.Abs(Sum2 - Sum1)) {
                    LastResult = Math.Abs(Sum2 - Sum1);
                }
            }
            Console.WriteLine(LastResult);
        }
    }
 
}