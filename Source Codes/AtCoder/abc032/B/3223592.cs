using System.Collections.Generic;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var num = ToInt32(ReadLine());
        var pass = new HashSet<string>();
        if (str.Length >= num)
        {
            for (var i = 0; i < str.Length-num+1; i++)
            {
                pass.Add(str.Substring(i, num));
            }
            WriteLine(pass.Count);
        }
        else WriteLine(0);
    }
}