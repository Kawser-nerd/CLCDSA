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
        switch(Console.ReadLine())
        {
            case "1":
                Console.WriteLine("Hello World");
                break;
            case "2":
                Console.WriteLine(int.Parse(Console.ReadLine()) +
                    int.Parse(Console.ReadLine()));
                break;
        }

    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}