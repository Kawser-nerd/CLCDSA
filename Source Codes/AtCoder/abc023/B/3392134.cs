using static System.Console;

class Program
{
    static void Main()
    {
        WriteLine(judge());
    }

    static int judge()
    {
        var n = int.Parse(NextStr());
        var s = NextStr();

        var t = "b";

        for (var i = 0; ; i++)
        {
            if (t == s)
                return i;
            else if (t.Length > n)
                break;
            t = MakeAccessory(t, i);
        }
        return -1;
    }

    static string MakeAccessory(string s, int i)
    {
        i %= 3;
        return "acb"[i] + s + "cab"[i];
    }

    static string NextStr()
    {
        string result = "";
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