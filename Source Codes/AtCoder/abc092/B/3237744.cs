using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var people = ToInt32(ReadLine());
        var input = ReadLine().Split(' ');
        var day = ToInt32(input[0]);
        var result = ToInt32(input[1]);
        for(var i = 0; i < people; i++)
        {
            var bet = ToInt32(ReadLine());
            result += 1 + (day-1) / bet;
        }
        WriteLine(result);
    }
}