using System;

namespace ABC055B
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            ulong res = 1;
            uint mod = 1000000007;
            for (uint i = 1; i <= N; i++)
            {
                res = (res * i) % mod;
            }

            Console.WriteLine(res);
        }
    }
}