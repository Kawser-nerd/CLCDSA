using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var n = NextInt();
        var dic = new Dictionary<int, bool>();
        var cnt = 0;

        for (var i = 0; i < n; i++)
        {
            var ai = NextInt();

            if (dic.ContainsKey(ai))
                cnt++;
            else
                dic[ai] = true;
        }
        WriteLine(cnt);
    }

    static int NextInt()
    {
        return int.Parse(NextStr());
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