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
        Console.WriteLine(Slove());
    }
    static string Slove()
    {        
        string[] inputs = Console.ReadLine().Split(); 
        int dir = (int.Parse(inputs[0]) + 112) % 3600;
        int dis = int.Parse(inputs[1]);
        string[] dirss =
        {
            "N",
            "NNE",
            "NE",
            "ENE",
            "E",
            "ESE",
            "SE",
            "SSE",
            "S",
            "SSW",
            "SW",
            "WSW",
            "W",
            "WNW",
            "NW",
            "NNW",
        };
        int[] dises =
        {
            6 * 3,
            6 * 16,
            6 * 34,
            6 * 55,
            6 * 80,
            6 * 108,
            6 * 139,
            6 * 172,
            6 * 208,
            6 * 245,
            6 * 285,
            6 * 327,
            int.MaxValue,
        };
        int power = Enumerable.Range(0, dises.Length).First(x => dis + 3 < dises[x]);
        return
            $"{(power == 0 ? "C" : dirss[dir * 16 / 3600])} {power}";
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}