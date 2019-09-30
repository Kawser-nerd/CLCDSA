using System;
using System.Collections.Generic;
using System.Linq;
//using System.Numerics;
class Program
{     
    
    public void Slove()
    {
        var inputs = Console.ReadLine().Split();
        int xCount = int.Parse(inputs[2]) - int.Parse(inputs[0]);
        int yCount = int.Parse(inputs[3]) - int.Parse(inputs[1]);
        List<char> result = new List<char>();
        foreach(int i in Enumerable.Range(0, xCount))
            result.Add('R');
        foreach(int i in Enumerable.Range(0, yCount))
            result.Add('U');
        foreach(int i in Enumerable.Range(0, xCount))
            result.Add('L');
        foreach(int i in Enumerable.Range(0, yCount + 1))
            result.Add('D');

        foreach(int i in Enumerable.Range(0, xCount + 1))
            result.Add('R');
        foreach(int i in Enumerable.Range(0, yCount + 1))
            result.Add('U');
        result.Add('L');
        result.Add('U');
        foreach(int i in Enumerable.Range(0, xCount + 1))
            result.Add('L');
        foreach(int i in Enumerable.Range(0, yCount + 1))
            result.Add('D');
        result.Add('R');
        System.Console.WriteLine(string.Join("", result));
    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}