using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
class Program
{    
    
    public void slove()
    {
        var inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = inputs[0];
        int m = inputs[1];
        int [] ball = Enumerable.Range(0, n).Select(x => 1).ToArray();
        bool[] possibility = new bool[n];
        possibility[0] = true;
        foreach(int i in Enumerable.Range(0, m))
        {
            inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int a = inputs[0] - 1;
            int b = inputs[1] - 1;
            ball[a]--;
            ball[b]++;
            if(possibility[a])
            {
                possibility[b] = true;
            }
            if(ball[a] == 0)
            {                
                possibility[a] = false;
            }
        }
        System.Console.WriteLine(possibility.Count(x => x));
    }
    
    static void Main(string[] args)
    {
        new Program().slove();
    }
}