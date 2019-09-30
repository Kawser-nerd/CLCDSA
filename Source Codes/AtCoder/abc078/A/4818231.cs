using System;
using System.Linq;
class Program
{
    static void Main()
    {
        char[] input = Array.ConvertAll(Console.ReadLine().Split(),char.Parse);
        //int input=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        string ans;
        if (input[0]<input[1])
        {
            ans = "<";
        }
        else if (input[1]<input[0])
        {
            ans = ">";
        }
        else
        {
            ans = "=";
        }
        Console.WriteLine(ans);
        Console.ReadLine();
    }
}