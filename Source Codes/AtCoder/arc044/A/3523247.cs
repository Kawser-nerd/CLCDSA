using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine();
        var num = ToInt32(input);
        if (num == 1) { WriteLine("Not Prime"); return; }
        if (num == 2 || num == 3 || num == 5) {WriteLine("Prime"); return; }
        
        if (num % 2 != 0 &&
            num%5 != 0 &&
            num % 3 != 0) WriteLine("Prime");
        else WriteLine("Not Prime");
    }
}