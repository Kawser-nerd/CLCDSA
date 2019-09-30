using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = 2025-ToInt32(ReadLine());
        for(var i = 1; i <= 9; i++)
        {
            var dif = num / i;
            if (dif == (double)num / i && dif < 10) WriteLine($"{i} x {dif}");
        }
    }
}