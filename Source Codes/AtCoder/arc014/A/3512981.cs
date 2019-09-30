using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        WriteLine(ToInt32(ReadLine()) % 2 == 0 ? "Blue" : "Red");
    }
}