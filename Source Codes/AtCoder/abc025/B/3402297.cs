using System.Linq;
using static System.Console;
using static System.Math;

class Program
{
    static void Main()
    {
        var vector = new string[] { "East", "", "West" };
        var n = NextInt();
        var a = NextInt();
        var b = NextInt();

        var x = 0;
        foreach (var i in Enumerable.Range(0, n))
        {
            x += Move(a, b, vector);
        }
        Output(x, vector);
    }

    static void Output(int x, string[] vector)
    {
        Write(vector[Sign(x) + 1]);
        if (Sign(x) != 0) Write(" ");
        WriteLine(Abs(x));
    }

    static int Move(int smallest, int largest, string[] vector)
    {
        var s = NextStr();
        var d = NextInt();

        var i = 0;
        foreach (var v in vector)
        {
            if (s == v)
                return Max(smallest, Min(largest, d)) * (i - 1);
            i++;
        }
        return 0;
    }

    static int NextInt()
    {
        return int.Parse(NextStr());
    }

    static string NextStr()
    {
        var result = "";
        while (true)
        {
            int tmp0 = Read();
            if (tmp0 < 0)
                break;
            var tmp = (char)tmp0;
            if (!string.IsNullOrWhiteSpace(tmp + ""))
                result += tmp;
            else if (tmp != '\r')
                break;
        }
        return result;
    }
}