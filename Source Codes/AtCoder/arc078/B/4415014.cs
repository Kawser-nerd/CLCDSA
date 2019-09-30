using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var dist1 = new int[num];
        var dist2 = new int[num];
        var ads = new List<int>[num];
        for (var i = 0; i < num; i++)
            ads[i] = new List<int>();
        for(var i = 0; i < num-1; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            ads[input[0] - 1].Add(input[1] - 1);
            ads[input[1] - 1].Add(input[0] - 1);
        }
        bfs(0, ads, dist1, new Queue<int>());
        bfs(num - 1, ads, dist2, new Queue<int>());
        var resfe = 0;
        var ressn = 0;
        for (var i = 1; i < num-1; i++)
            if (dist1[i] <= dist2[i]) resfe++;
            else ressn++;
        WriteLine(resfe > ressn ? "Fennec" : "Snuke");
    }
    private static void bfs(int st,List<int>[] ads,int[] dist,Queue<int> queue)
    {
        queue.Enqueue(st);
        while (queue.Count != 0)
        {
            var index = queue.Dequeue();
            foreach (var ad in ads[index])
                if (ad!=st&&dist[ad] == 0)
                {
                    dist[ad] = dist[index] + 1;
                    queue.Enqueue(ad);
                }
            
        }
    }
}