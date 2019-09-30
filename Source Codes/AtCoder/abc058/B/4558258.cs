using System;
using System.Text;

public class Program
{
    static void Main()
    {
        var o = Console.ReadLine();
        var e = Console.ReadLine();
        var sb = new StringBuilder();
        var oIndex = 0;
        var eIndex = 0;
        for (int i = 0; i < o.Length + e.Length; i++)
        {
            if (i % 2 == 0)
            {
                sb.Append(o[oIndex]);
                oIndex++;
            }
            else
            {
                sb.Append(e[eIndex]);
                eIndex++;
            }
        }
        Console.WriteLine(sb.ToString());
    }
}