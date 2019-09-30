using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var height = ToInt32(input[0]);
        var width = ToInt32(input[1]);
        WriteLine(height * (width - 1) + width * (height - 1));
    }
}