using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine();
        var num = ToInt32(input);
        var sum = 0;
        for(var i = 0; i < input.Length; i++)
        {
            sum += ToInt32(input.Substring(i,1));
        }
        var result = num % sum==0 ? "Yes" : "No";
        WriteLine(result);
    }
}