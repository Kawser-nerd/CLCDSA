using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var small = ToInt32(input[0]);
        var big = ToInt32(input[1]);
        var num = big - small;
        WriteLine((double)1 / 2 * num * (num + 1) - big);
    }
}