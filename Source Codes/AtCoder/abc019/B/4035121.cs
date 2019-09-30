using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public void Slove()
    {
        string input = Console.ReadLine();
        List<string> result = new List<string>();

        char before = input[0];
        int count = 1;
        foreach(char c in input.Skip(1))
        {
            if(before != c)
            {
                result.Add($"{before}{count}");
                count = 1;
                before = c;
            }
            else
                count++;
        }
        result.Add($"{before}{count}");
        Console.WriteLine(string.Join("", result));
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}