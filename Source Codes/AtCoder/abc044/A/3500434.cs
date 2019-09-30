using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;


namespace _20180502_pra
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var K = int.Parse(Console.ReadLine());
            var X = int.Parse(Console.ReadLine());
            var Y = int.Parse(Console.ReadLine());
            if(N<=K)
                Console.WriteLine(N*X);
            else
                Console.WriteLine(K*X+(N-K)*Y);
        }
    }
}