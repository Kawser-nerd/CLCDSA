using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt64(ReadLine());
        var min = 11;
        for(var i = 1L; i * i <= num; i++)
        {
            if (num % i != 0) continue;
            var b = num / i;
            var max = Max(i.ToString().Length, b.ToString().Length);
            min = Min(min, max);
        }
        WriteLine(min);
    }
}