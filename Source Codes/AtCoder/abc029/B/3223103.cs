using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var result = 0;
        for(var i = 0; i < 12; i++)
        {
            var str = ReadLine();
            if (str.Contains("r")) result++;
        }
        WriteLine(result);
    }
}