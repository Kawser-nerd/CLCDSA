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
        string[] inputs =
            Console.ReadLine().Split();
        int height = int.Parse(inputs[0]);
        int width = int.Parse(inputs[1]);
        int limit = int.Parse(inputs[2]);
        int startX = 0, startY = 0, goalX = 0, goalY = 0;
        string[] map =
            Enumerable.Range(0, height)
            .Select(x => Console.ReadLine())
            .ToArray();
        foreach(int h in Enumerable.Range(0, height))
            foreach(int w in Enumerable.Range(0, width))
            {
                if(map[h][w] == 'S')
                {
                    startX = w;
                    startY = h;
                }
                else if(map[h][w] == 'G')
                {
                    goalX = w;
                    goalY = h;
                }
            }
        int[][][] distance =
            Enumerable.Range(0, height)
            .Select(x => Enumerable.Range(0, width)
                .Select(y => Enumerable.Range(0, width + height)
                    .Select(z => int.MaxValue).ToArray())
                .ToArray())
            .ToArray();
        distance[startY][startX][0] = 0;
        var que = new Queue<int[]>();
        que.Enqueue(new int[] { startX, startY, 0});
        int[][] delta = new int[][]
        {
            new int[]{ 0, 1},
            new int[]{ 0,-1},
            new int[]{ 1, 0},
            new int[]{-1, 0},
        };
        int move = 1;
        while(que.Any())
        {
            foreach(int i in Enumerable.Range(0, que.Count))
            {
                int[] p = que.Dequeue();
                int x = p[0];
                int y = p[1];
                int black = p[2];
                foreach(var next in delta.Select(a => new {X = a[0] + x, Y = a[1] + y }))
                {
                    if(next.X < 0 || next.X >= width ||
                        next.Y < 0 || next.Y >= height)
                        continue;
                    int nBlack = black + (map[next.Y][next.X] == '#' ? 1 : 0);
                    //Console.WriteLine($"{next.Y} {next.X} {map[next.Y][next.X]}");
                    if(nBlack < width + height &&
                        distance[next.Y][next.X][nBlack] > move)
                    {
                        //Console.WriteLine($"{next.Y} {next.X} {move}");
                        distance[next.Y][next.X][nBlack] = move;
                        if(next.X != goalX || next.Y != goalY)
                        {
                            int[] item = new int[] 
                            { 
                                next.X, 
                                next.Y, 
                                nBlack
                            };
                            que.Enqueue(item);
                        }
                    }
                }
            }
            move++;
        }
        int max = 
            distance[goalY][goalX]
            //.Select(x => {Console.WriteLine(x); return x; })
            .Skip(1)
            .Select((x, i) => (limit - x) / (i + 1))
            .Max() + 1;
        Console.WriteLine(max);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}