using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        WriteLine(num % 100 == 0 ? num % 400 == 0 ? "YES" : "NO" : num % 4 == 0 ? "YES" : "NO");
    }
}