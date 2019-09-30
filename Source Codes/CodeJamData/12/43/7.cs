using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class ProbD
    {
        public static void Run()
        {
        
        TextReader reader = new StreamReader("C:/Users/user/Desktop/CodeJam/C-small-attempt0.in");
            TextWriter writer = new StreamWriter("C:/Users/user/Desktop/CodeJam/probD.txt");

            int testCases = int.Parse(reader.ReadLine());

            for (int testcase = 0; testcase < testCases; testcase++)
            {
                try
                {

                    int Peaks = int.Parse(reader.ReadLine());
                    int[] big = new int[Peaks];
                    string[] words = reader.ReadLine().Split(' ');
                    for (int peak = 0; peak < Peaks -1; peak++)
                    {
                        big[peak] = int.Parse(words[peak]);
                    }

                    bool result = true;

                    var pair = new Pair(0, big.Count());
                     Separate(pair , big);

                     int[] heights = new int[big.Count()];
                     foreach (var item in pair.InnerInt)
                     {
                         CreateHeights(item, 0, 100000, ref heights);

                     }

                    writer.Write("Case #" + (testcase + 1) + ":");
                    Console.Write("Case #" + (testcase + 1) + ": ");
                    for (int i = 0; i < heights.Count(); i++)
                    {
                        writer.Write(" " +heights[i]);
                        Console.Write(" " + heights[i]);
                    }
                    writer.Write(writer.NewLine);
                    Console.Write(writer.NewLine);
                    writer.Flush();
                }
                catch
                {
                    writer.WriteLine("Case #" + (testcase + 1) + ": " + "Impossible");
                    Console.WriteLine("Case #" + (testcase + 1) + ": " + "Impossible");
                    writer.Flush();
                }
            }
            Console.ReadLine();
        }

        private static void CreateHeights(Pair pair, int steigung, int startHeight, ref int[] heights)
        {
            heights[pair.Rad - 1] = startHeight;
            heights[pair.Pos - 1] = startHeight - steigung * (pair.Rad - pair.Pos);
            foreach (var child in pair.InnerInt)
            {
                int nextheight = child.Rad == pair.Rad ? startHeight : startHeight - (int) ((pair.Rad - child.Rad) * (steigung+1)); 
                CreateHeights(child, steigung + 1 + 2* (pair.Rad - child.Rad), nextheight, ref heights);
            }

        }
        private static List<Pair> Separate(Pair pair, int[] big)
        {
            int pos = pair.Pos + 1;
            if (pos == big.Count())
            {
                return pair.InnerInt;
            }
            while (pair.Rad - pos >= 1)
            {
                if (big[pos-1] > pair.Rad)
                    throw new Exception();
                var newpair = new Pair(pos, big[pos-1]);
                pair.InnerInt.Add(newpair);
                Separate(newpair, big);
                pos = big[pos-1];
            }

            return pair.InnerInt;
        }

        class Pair
        {
            public Pair(int pos, int rad)
            {
                Pos = pos;
                Rad = rad;
                InnerInt = new List<Pair>();
            }
            public List<Pair> InnerInt { get; set; }
            public int Pos { get; set; }
            public int Rad { get; set; }
        }
    }
}
