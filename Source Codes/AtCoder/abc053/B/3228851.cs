using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        WriteLine(str.Substring(str.IndexOf("A"), str.LastIndexOf("Z")+1- str.IndexOf("A")).Length);
    }
}