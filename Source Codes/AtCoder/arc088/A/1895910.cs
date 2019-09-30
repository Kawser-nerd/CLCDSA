using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace template
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            int ret;
            for (ret = 0; x[0] <= x[1]; x[0] *= 2) ret++;
            Console.WriteLine(ret);
        }
    }
}