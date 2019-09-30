using static System.Console;

class Program
{
    static void Main()
    {
        var n = NextInt();
        var m = new int[] { -1, 1 }[n % 2];
        WriteLine(n + m);
    }


    static string NextString()
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

    static int NextInt()
    {
        return int.Parse(NextString());
    }
}