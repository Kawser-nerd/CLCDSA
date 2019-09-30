using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        for (var i = 2; i * i <= num; i++)
            if (num % i == 0) { WriteLine("NO"); return; }
        WriteLine(num!=1?"YES":"NO");
    }
}