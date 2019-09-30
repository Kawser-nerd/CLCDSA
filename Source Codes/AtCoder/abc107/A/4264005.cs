using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A.Train
{
    class Program
    {
        static void Main(string[] args)
        {
            var NI =  Console.ReadLine().Split(null).Select(int.Parse).ToArray();

            int ans = NI[0] - NI[1] + 1;

            Console.WriteLine(ans);
        }
    }
}