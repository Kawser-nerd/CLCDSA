using System;

namespace Wandbox
{
    class Program
    {
        static void Main(string[] args)
        {
            var imp = Console.ReadLine().Split(' ');
            int N = int.Parse(imp[0]);
            int K = int.Parse(imp[1]);
            int ask = N%K;
            if(ask == 0) Console.Write("0");
            else Console.Write('1');
        }
    }
}