//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

public class Test
{
    public static void Main()
    {
        var N = long.Parse(Console.ReadLine());

        var adj = new List<long>[N];
        for (int i = 0; i < N; i++)
        {
            adj[i] = new List<long>();
        }

        for (var i = 0; i < N - 1; i++)
        {
            var line1 = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();

            adj[line1[0] - 1].Add(line1[1] - 1);
            adj[line1[1] - 1].Add(line1[0] - 1);
        }
        
        //*** 1 ?? N ?????????? ***
        long[] prev = new long[N];
        bool finished = false;
        bool[] filled2 = new bool[N];

        Queue<long> q = new Queue<long>();
        q.Enqueue(0);

        while (!finished)
        {
            var node = q.Dequeue();
            foreach (var child in adj[node])
            {
                if (!filled2[child])
                {
                    filled2[child] = true;
                    q.Enqueue(child);
                    prev[child] = node;

                    if (child == N - 1)
                    {
                        finished = true;
                        break;
                    }
                }
            }
        }

        //*** 1 ?? N ????????????
        List<long> myPath = new List<long>();
        long next = N - 1;
        while (next != 0)
        {
            myPath.Add(next);
            next = prev[next];
        }
        myPath.Add(0);
        myPath.Reverse();  // 1 ?? N ?

        //Console.WriteLine(string.Join(",", myPath.Select(x => x + "").ToArray()));

        //*** ?????????? ***
        var player1Queue = new Queue<long>();
        var player2Queue = new Queue<long>();
        bool[] filled = new bool[N];
        int player1ptr = 0;
        int player2ptr = 0;

        for (int i = 0; i < (myPath.Count + 1) / 2; i++)
        {
            player1Queue.Enqueue(myPath[i]);
            filled[myPath[i]] = true;
            player1ptr++;
        }

        for (int i = (myPath.Count + 1) / 2; i < myPath.Count; i++)
        {
            player2Queue.Enqueue(myPath[i]);
            filled[myPath[i]] = true;
            player2ptr++;
        }


        while (player1Queue.Count != 0)
        {
            var next2 = player1Queue.Dequeue();

            foreach (var child in adj[next2])
            {
                if (filled[child] == false)
                {
                    filled[child] = true;
                    player1ptr++;
                    player1Queue.Enqueue(child);
                }
            }
        }
        
        while (player2Queue.Count != 0)
        {
            var next2 = player2Queue.Dequeue();

            foreach (var child in adj[next2])
            {
                if (filled[child] == false)
                {
                    filled[child] = true;
                    player2ptr++;
                    player2Queue.Enqueue(child);
                }
            }
        }

        //Console.WriteLine(player1ptr);
        //Console.WriteLine(player2ptr);

        Console.WriteLine((player1ptr <= player2ptr) ? "Snuke" : "Fennec");
    }
}