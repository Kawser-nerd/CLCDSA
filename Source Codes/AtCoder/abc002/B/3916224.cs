using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

class Program
{     
    public Program()
    {
        Console.WriteLine(string.Join("",Console.ReadLine().Where(x => !"aiueo".Contains(x))));
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}