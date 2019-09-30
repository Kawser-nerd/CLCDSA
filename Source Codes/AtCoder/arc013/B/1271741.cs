using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC013B
{
    class Program
    {
        static void Main(string[] args)
        {
            int C = int.Parse(Console.ReadLine());
            List<int[]> baggages = new List<int[]>();
            int[] a;
            string[] vals;
            for (int i=0; i < C; i++)
            {
                vals = Console.ReadLine().Split(' ');
                a = new int[3];
                a[0] = int.Parse(vals[0]);
                a[1] = int.Parse(vals[1]);
                a[2] = int.Parse(vals[2]);
                Array.Sort(a);
                baggages.Add(a);
            }

            int max0 = 0, max1 = 0, max2 = 0;
            foreach(var b in baggages)
            {
                if (max0 < b[0])
                    max0 = b[0];
                if (max1 < b[1])
                    max1 = b[1];
                if (max2 < b[2])
                    max2 = b[2]; 
            }

            Console.WriteLine(max0 * max1 * max2);
        }
    }
}