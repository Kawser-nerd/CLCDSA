using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var c = ReadLine();
        WriteLine(ReadLine().Replace(c, ""));
    }
}