using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

class Program
{
    public void Slove()
    {    
        string[] inputs = Console.ReadLine().Split('+');
        Console.WriteLine(inputs.Count(x => !x.Contains('0')));
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}