using System.Text.RegularExpressions;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var num1 = ToInt32(input[0]);
        var num2 = ToInt32(input[1]);
        var str = ReadLine();
        var rgx = new Regex(@"(\d+)-(\d+)");
        if (rgx.IsMatch(str))
        {
            var match = rgx.Match(str);
            if (match.Groups[1].Length == num1 && match.Groups[2].Length == num2) WriteLine("Yes");
            else WriteLine("No");
        }
        else WriteLine("No");
    }
}