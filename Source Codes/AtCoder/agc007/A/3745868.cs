using System;
using System.Linq;
using System.Collections.Generic;
class c
{
    static void Main()
    {
        var hw = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        bool judge = true;
        var list = new List<string>();
        list.Add("##" + string.Join("", Enumerable.Repeat('.', hw[1])));
        for (int i = 0; i < hw[0]; i++) list.Add("." + Console.ReadLine() + ".");
        list.Add(string.Join("", Enumerable.Repeat('.', hw[1])) + "##");
        for (int i = 1; i < list.Count() - 1; i++)
        {
            for (int j = 1; j < list[0].Length - 1; j++)
            {
                if (list[i][j] == '#' && (list[i - 1][j] == list[i][j - 1] || list[i + 1][j] == list[i][j + 1])) judge = false;
            }
        }
        Console.WriteLine(judge ? "Possible" : "Impossible");
    }
}