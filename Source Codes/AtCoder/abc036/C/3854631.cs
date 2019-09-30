using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        var n = NextInt();
        var arr = new int[n];
        var lst = new List<int>();
        var st = new HashSet<int>();
        foreach (var i in Enumerable.Range(0, n))
        {
            var a = NextInt();
            arr[i] = a;
            st.Add(a);
        }

        foreach (var s in st)
        {
            lst.Add(s);
        }
        lst.Sort();
        var dic = new Dictionary<int, int>();
        foreach (var i in Enumerable.Range(0, lst.Count))
        {
            dic[lst[i]] = i;
        }

        foreach (var i in Enumerable.Range(0, n))
        {
            WriteLine(dic[arr[i]]);
        }
    }

    static int NextInt()
    {
        return int.Parse(NextString());
    }

    static string NextString()
    {
        var result = new List<char>();
        while (true)
        {
            int next = Read();
            if (next < 0)
            {
                break;
            }
            var nextChar = (char)next;
            if (!char.IsWhiteSpace(nextChar))
            {
                result.Add(nextChar);
            }
            else if (nextChar != '\r')
            {
                break;
            }
        }
        return string.Join("", result);
    }
}