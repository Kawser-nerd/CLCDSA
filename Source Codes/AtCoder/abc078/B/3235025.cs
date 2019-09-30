using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var chair = ToInt32(input[0]);
        var human = ToInt32(input[1]);
        var between = ToInt32(input[2]);
        var result = 0;
        while (true)
        {
            chair -= between;
            chair -= human;
            if (chair < between) break;
            result++;
        }
        WriteLine(result);
    }
}