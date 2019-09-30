using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var result = num % 2 == 0 ? num - 1 : num + 1;
        WriteLine(result);
    }
}