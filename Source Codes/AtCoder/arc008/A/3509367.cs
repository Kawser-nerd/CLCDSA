using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        WriteLine(Min(num / 10 * 100 + num % 10 * 15,(num/10+1)*100));
    }
}