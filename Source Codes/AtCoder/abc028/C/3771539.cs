using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static int[] abc;
    static List<int> ans;

    static void Main()
    {
        abc = new int[5];
        foreach (var i in Enumerable.Range(0, abc.Length))
        {
            abc[i] = NextInt();
        }
        ans = new List<int>();
        DFS(new int[0]);
        ans.Sort(); ;
        WriteLine(ans[ans.Count() - 3]);
    }

    static void DFS(int[] arr)
    {
        if (arr.Count() == 3 && !ans.Contains(arr.Sum()))
        {
            ans.Add(arr.Sum());
        }
        foreach (var v in abc)
        {
            if (!arr.Contains(v))
            {
                var tmp = new int[arr.Count() + 1];
                for (var i = 0; i < arr.Count(); i++)
                {
                    tmp[i] = arr[i];
                }
                tmp[arr.Count()] = v;
                DFS(tmp);
            }
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