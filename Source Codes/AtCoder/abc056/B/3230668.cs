using static System.Console;
using static System.Convert;
class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var length = ToInt32(input[0]);
        var num1 = ToInt32(input[1]);
        var num2 = ToInt32(input[2]);
        var result = num1 <= num2 ? num2 - (num1 + length) : num1 - (num2 + length);
        if (result < 0) result = 0;
        WriteLine(result);
    }
}