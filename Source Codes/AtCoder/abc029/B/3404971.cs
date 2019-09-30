using static System.Console;

class Program
{
    static void Main()
    {
        const int n = 12;

        var cnt = 0;
        for (var i = 0; i < n; i++)
        {
            if (Judge()) cnt++;
        }
        WriteLine(cnt);
    }

    static bool Judge()
    {
        var s = NextStr();
        foreach (var ch in s)
        {
            if (ch == 'r') return true;
        }
        return false;
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