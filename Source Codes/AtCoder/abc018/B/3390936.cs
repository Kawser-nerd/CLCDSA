using static System.Console;

class Program
{
    static void Main()
    {
        var s = ReadLine();
        var n = int.Parse(ReadLine());

        for (var i = 0; i < n; i++)
            s = fn(s);

        WriteLine(s);
    }

    static string fn(string s)
    {
        var result = "";
        var l = int.Parse(Scan()) - 1;
        var r = int.Parse(Scan()) - 1;

        for (var j = 0; j < s.Length; j++)
        {
            if (l <= j && j <= r)
                result += s[r + l - j];
            else
                result += s[j];
        }
        return result;
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