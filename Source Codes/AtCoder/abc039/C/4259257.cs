using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static IEnumerable<int> ChainEqual(string str)
    {
        foreach(int i in str.Skip(1).Select((x, i) => i))
        {
            if(str[i] == str[i + 1])
                yield return i;
        }
    }
    public void slove()
    {
        string[] scale =
        {
            "La",
            "Si",
            "Do",
            "Re",
            "Mi",
            "Fa",
            "So",
        };
        string input = Console.ReadLine();
        int[] index = ChainEqual(input).ToArray();
        //System.Console.WriteLine(string.Join(",", index));
        string result = index[1] - index[0] == 7 ?
            scale[scale.Length - 1 - (index[0] / 2 + 2) % scale.Length] :
            scale[scale.Length - 1 - (index[0] / 2 + 5) % scale.Length];
        System.Console.WriteLine(result);            
    }
    static void Main(string[] args)
    {
        new Program().slove();
    }
}