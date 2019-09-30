using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Hello
{
    public static void Main()
    {
        Console.WriteLine(program(new string[] { Console.ReadLine(), Console.ReadLine() }));
    }

    private static string program(string[] args)
    {
        var n = int.Parse(args[0]);
        var s = args[1].ToCharArray();

        return (new String[] { "SS", "SW", "WS", "WW" }).Select(animals =>
            s.Aggregate(new StringBuilder(animals, n),
                (t, elem) => t.Append(isXor(t[t.Length - 1], elem) ? not(t[t.Length - 2]) : t[t.Length - 2]))
        )
        .Select(sb => sb.ToString())
        .FirstOrDefault(result => result.Substring(0, 2) == result.Substring(result.Length - 2, 2))?.Substring(1, n) ?? "-1";
    }

    private static bool isXor(char animal, char ans) => animal == 'S' && ans == 'x' || animal == 'W' && ans == 'o';

    private static char not(char animal) => animal == 'S' ? 'W' : 'S';
}