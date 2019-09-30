using static System.Console;

class Program
{
    static void Main()
    {
        var ans = "YES";
        var X = Scan();
        X = X.Replace("ch", "");

        foreach (var c in X)
        {
            if (!"oku".Contains(c + ""))
                ans = "NO";
        }
        WriteLine(ans);
    }

    static string Scan()
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