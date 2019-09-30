using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practice
{
    class Program
    {
        static void Main(string[] args)
        {
            string row = Console.ReadLine();
            string[] szArr = row.Split(' ');
            int a = int.Parse(szArr[0]);
            int b = int.Parse(szArr[1]);
            int c = int.Parse(szArr[2]);
            long x = int.Parse(szArr[3]);
            long y = int.Parse(szArr[4]);

            long minPrice = long.MaxValue;

            long maxZ = Math.Max(x, y)  *2;// ??????
            for( int z = 0; z <= maxZ; z+=2)
            {
                long price = c * z + a * Math.Max(0, (x - z / 2)) + b * Math.Max(0,(y - z / 2));
                if( price < minPrice)
                {
                    minPrice = price;
                }
            }

            Console.WriteLine(minPrice);
        }
    }
}