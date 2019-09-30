using static System.Console;
using static System.Convert;
class Program
{
    static void Main(string[] args)
    {
        var num1 = ToDouble(ReadLine());
        var num2 = ToDouble(ReadLine());
        if (num1 > num2) WriteLine("GREATER");
        else if (num1 < num2) WriteLine("LESS");
        else WriteLine("EQUAL");
    }
}