using System;

namespace atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var imp = Console.ReadLine().Split(' ');
            int N = int.Parse(imp[0]);
            int i = int.Parse(imp[1]);
            
            Console.Write((N-1)*(i-1));
           
        }
    }
}