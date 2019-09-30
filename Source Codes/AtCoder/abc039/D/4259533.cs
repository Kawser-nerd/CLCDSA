using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static IEnumerable<char> GetAroundChar(string[] src, int x, int y)
    {
        foreach(int sy in Enumerable.Range(-1, 3).Select(a => y + a).Where(a => a >=0 && a < src.Length))
            foreach(int sx in Enumerable.Range(-1, 3).Select(a => x + a).Where(a => a >=0 && a < src[sy].Length))
            {
                yield return src[sy][sx];
            }
    }
    public void slove()
    {
        char black = '#';
        char white = '.';
        var inputs = Console.ReadLine().Split();
        int height = int.Parse(inputs[0]);
        int width = int.Parse(inputs[1]);
        string[] data =
            Enumerable.Range(0, height)
            .Select(x => Console.ReadLine())
            .ToArray();
        string[] baseData =
            Enumerable.Range(0, height)
            .Select(y => string.Join("",
                Enumerable.Range(0, width)
                .Select(x => GetAroundChar(data, x, y).All(a => a == black) ? black : white)))
            .ToArray();
        bool judge = 
            Enumerable.Range(0, height)
            .All(y => 
                Enumerable.Range(0, width)
                .All(x => GetAroundChar(baseData, x, y).Any(a => a == black) == (data[y][x] == black)
                )
            );
        if(judge)
        {
            System.Console.WriteLine("possible");
            System.Console.WriteLine(string.Join("\n", baseData));
        }
        else
        {
            System.Console.WriteLine("impossible");
            //System.Console.WriteLine(string.Join("\n", baseData));
        }
    }
    static void Main(string[] args)
    {
        new Program().slove();
    }
}