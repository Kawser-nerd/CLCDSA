using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    static IEnumerable<char> Get(int count)
    {
        if(count == 0)
        {
            yield return 'b';
            yield break;
        }
        int p = count % 3;
        if(p == 1)
            yield return 'a';
        else if(p == 2)
            yield return 'c';
        else
            yield return 'b';
        foreach(char c in Get(count - 1))
            yield return c;
        if(p == 1)
            yield return 'c';
        else if(p == 2)
            yield return 'a';
        else
            yield return 'b';
    }

    public void Slove()
    {
        int n = int.Parse(Console.ReadLine());
        string input = Console.ReadLine().Trim();
        int count = input.Length / 2;
        string makeStr = string.Join("", Get(count));
        //Console.WriteLine($"{makeStr} {input}");
        bool judge = makeStr.SequenceEqual(input);
        //Console.WriteLine(judge);
        Console.WriteLine(judge ? count : -1);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}