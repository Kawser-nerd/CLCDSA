using System;

class Program
{
    static void Main(string[] args)
    {
        var str = Console.ReadLine();
        var str2 = Console.ReadLine();

        var reverse = "";
        for(var i = 0; i < str.Length; i++)
        {
            reverse += str.Substring(2 - i, 1);
        }
        if (str2 == reverse) Console.WriteLine("YES");
        else Console.WriteLine("NO");
    }
}