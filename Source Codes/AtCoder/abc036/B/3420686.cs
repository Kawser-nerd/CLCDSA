using static System.Console;

class Program
{
    static void Main()
    {
        string[] square = Input();
        WriteLine(string.Join("\n", Rotated(square)));
    }

    static string[] Input()
    {
        var n = int.Parse(ReadLine());
        var s = new string[n];

        for (var i = 0; i < n; i++)
        {
            s[i] = ReadLine();
        }
        return s;
    }

    static string[] Rotated(string[] s)
    {
        var n = s.Length;
        var result = new string[n];

        for (var i = 0; i < n; i++)
        {
            for (var j = 1; j <= n; j++)
            {
                result[i] += s[n - j][i];
            }
        }
        return result;
    }
}