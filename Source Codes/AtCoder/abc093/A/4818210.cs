using System;
using System.Linq;
class Program
{
    static void Main()
    {
        //int[] input = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        //int input=int.Parse(Console.ReadLine());
        string a = Console.ReadLine();
        Console.WriteLine(a.Contains("a")&& a.Contains("b") && a.Contains("c") ?"Yes":"No");
        Console.ReadLine();
    }
}