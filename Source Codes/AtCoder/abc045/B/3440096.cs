using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var s = new Dictionary<int, string> { };

        for (var i = 0; i < 3; i++)
            s['A' + i] = NextString();

        int turn = 'A';

        while (s[turn] != "")
        {
            var pre = turn;
            turn = s[turn][0] - 'a' + 'A';
            s[pre] = s[pre].Remove(0, 1);
        }
        WriteLine((char)turn);
    }

    static string NextString()
    {
        var result = new List<char>();
        while (true)
        {
            int next = Read();
            if (next < 0)
                break;
            var nextChar = (char)next;
            if (!char.IsWhiteSpace(nextChar))
                result.Add(nextChar);
            else if (nextChar != '\r')
                break;
        }
        return string.Join("", result);
    }
}