using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;


class Program
{
    static IEnumerable<string> MakeStr(int len, string str)
    {
        if(str.Length == len)
        {
            yield return str; 
        }
        else
        {
            foreach(string c in "abc".SelectMany(x => MakeStr(len, str + x)))
            {
                yield return c;
            }
        }
    }
    public void Slove()
    {      
        string input = Console.ReadLine();
        int n = int.Parse(input);
        Console.WriteLine(string.Join("\n",MakeStr(n, "")));
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}