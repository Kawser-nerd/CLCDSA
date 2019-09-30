using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using Debug = System.Diagnostics.Debug;

class P
{
    static int segTreeSize;
    static int[] sections = null;
    static void Main()
    {
        var nk = Console.ReadLine().Split().Select(int.Parse).ToList();
        var x = Console.ReadLine().Split().Select(int.Parse).ToList();
        //var x = Enumerable.Range(1, nk[0]).ToList();
        var indexes = x.Select((a, b) => new Tuple<int, int>(a, b)).OrderBy(a => a.Item1).Select(a => a.Item2).ToArray();
        DateTime start = DateTime.Now;
        segTreeSize = 1;
        while (segTreeSize <= nk[0]) segTreeSize *= 2;
        sections = new int[segTreeSize * 2];
        for (int i = 0; i < nk[1] - 1; i++)
        {
            Update(x[i] - 1, 1);
        }
        StringBuilder builder = new StringBuilder();
        for (int i = nk[1] - 1; i < nk[0]; i++)
        {
            Update(x[i] - 1, 1);
            int currentSection = 1;
            int remain = nk[1];
            while (currentSection < segTreeSize)
            {
                currentSection *= 2;
                if (sections[currentSection] < remain)
                {
                    remain -= sections[currentSection];
                    currentSection++;
                }
            }
            builder.Append(indexes[currentSection - segTreeSize] + 1);
            builder.AppendLine();
        }
        DateTime end = DateTime.Now;
        Console.Write(builder.ToString());
        //Debug.WriteLine((end - start).TotalMilliseconds);
    }

    static void Update(int i, int x)
    {
        var ind = segTreeSize + i;
        sections[ind] = x;
        while ((ind >>= 1) != 0)
        {
            sections[ind] = sections[ind * 2] + sections[ind * 2 + 1];
        }
    }
}