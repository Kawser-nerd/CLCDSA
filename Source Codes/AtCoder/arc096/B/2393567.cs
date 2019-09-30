using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        //?????????
        //
        long[] nc = Console.ReadLine().Split().Select(long.Parse).ToArray();
        //x????(??)?v????
        //??????????
        Sushi[] sushis = Enumerable.Repeat(0, (int)nc[0]).Select(_ => new Sushi(Console.ReadLine().Split().Select(long.Parse).ToArray())).ToArray();

        //???????
        long[] calDPClock = new long[sushis.Length];
        long[] ClockMax = new long[sushis.Length];
        calDPClock[0] = sushis[0].Cal - sushis[0].Dist;
        ClockMax[0] = Max(0, calDPClock[0] - sushis[0].Dist);
        for (long i = 1; i < calDPClock.Length; i++)
        {
            calDPClock[i] = calDPClock[i - 1] + sushis[i].Cal - (sushis[i].Dist - sushis[i - 1].Dist);
            ClockMax[i] = Max(ClockMax[i - 1], calDPClock[i] - sushis[i].Dist);
        }

        long[] calDPAntiClock = new long[sushis.Length];
        long[] antiClockMax = new long[sushis.Length];
        calDPAntiClock[calDPAntiClock.Length - 1] = sushis[sushis.Length - 1].Cal - (nc[1] - sushis[sushis.Length - 1].Dist);
        antiClockMax[calDPAntiClock.Length - 1] = Max(0, calDPAntiClock[sushis.Length - 1] - (nc[1] - sushis[sushis.Length - 1].Dist));
        for (int i = calDPAntiClock.Length - 2; i >= 0; i--)
        {
            calDPAntiClock[i] = calDPAntiClock[i + 1] + sushis[i].Cal - ((nc[1] - sushis[i].Dist) - (nc[1] - sushis[i + 1].Dist));
            antiClockMax[i] = Max(antiClockMax[i + 1], calDPAntiClock[i] - (nc[1] - sushis[i].Dist));
        }


        long max = Max(0, Max(calDPClock.Last(), calDPAntiClock.First()));
        for (int i = 0; i < sushis.Length - 1; i++)
        {
            max = Max(max, calDPClock[i] + antiClockMax[i + 1]);
        }
        for (int i = sushis.Length - 1; i >= 1; i--)
        {
            max = Max(max, calDPAntiClock[i] + ClockMax[i - 1]);
        }
        Console.WriteLine(max);
    }
}
struct Sushi
{
    public long Dist;
    public long Cal;
    public Sushi(long dist,long cal)
    {
        Dist = dist;
        Cal = cal;
    }
    public Sushi(long[] a) : this(a[0], a[1]) { }
}