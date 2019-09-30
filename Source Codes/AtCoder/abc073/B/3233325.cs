using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var result = 0;
        for(var i = 0; i < num; i++)
        {
            var input = ReadLine().Split(' ');
            result += ToInt32(input[1]) - ToInt32(input[0]) + 1;
        }

        WriteLine(result);
    }
}