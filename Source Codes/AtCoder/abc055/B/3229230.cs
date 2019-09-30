using System;
using static System.Console;
using static System.Convert;
class Program
{
    static void Main(string[] args)
    {
        var num = ToUInt64(ReadLine());
        ulong result = 1;
        var mod = (ulong)(Math.Pow(10, 9) + 7);
        for(ulong i = 0; i < num; i++)
        {
            result *= (num - i) % mod;
            result %= mod;
        }
        WriteLine(result);
    }
}