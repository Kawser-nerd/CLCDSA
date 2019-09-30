using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam2012
{
    public class C1BA
    {
        private string mInputFile = @"E:\work\codejam2012\data\1C\A-large.in";

        static void Main(string[] args)
        {
            var p = new C1BA();
            p.Run();
            Console.WriteLine("Done");
            Console.ReadLine();
        }

        public void Run()
        {
            Console.WriteLine(mInputFile);
            Console.WriteLine(mInputFile + ".out");
            using (StreamWriter sw = new StreamWriter(mInputFile + ".out"))
            using (StreamReader sr = new StreamReader(mInputFile))
            {
                int testNum = int.Parse(sr.ReadLine());
                for (int i = 0; i < testNum; i++)
                {
                    RunTest(i + 1, sr, sw);
                }
            }
        }

        private int[] ReadIntsFromLine(StreamReader sr)
        {
            string[] splits = sr.ReadLine().Split();
            return splits.Select(x => int.Parse(x)).ToArray();
        }

        private IEnumerator<string> ReadStrings(StreamReader sr)
        {
            string line = null;
            while ((line = sr.ReadLine()) != null)
            {
                foreach (string split in line.Split())
                    yield return split;
            }
        }

        private void RunTest(int testNum, StreamReader sr, StreamWriter sw)
        {
            int N = ReadIntsFromLine(sr)[0];

            List<int>[] edges = new List<int>[N];
            for (int i = 0; i < N; i++)
            {
                var ints = ReadIntsFromLine(sr);
                int M = ints[0];
                edges[i] = new List<int>();
                for (int j = 0; j < M; j++)
                {
                    edges[i].Add(ints[j+1]-1);
                }
            }

            for (int i = 0; i < N; i++)
            {
                if (HasDiamondFrom(i, N, edges))
                {
                    sw.WriteLine("Case #{0}: Yes", testNum);
                    return;
                }
            }
            sw.WriteLine("Case #{0}: No", testNum);
        }

        private bool HasDiamondFrom(int node, int N, List<int>[] edges)
        {
            Queue<int> queue = new Queue<int>();
            queue.Enqueue(node);
            bool[] marks = new bool[N];
            while (queue.Count > 0)
            {
                int currentNode = queue.Dequeue();
                marks[currentNode] = true;

                //for (int i = 0; i < edges[currentNode].Count; i++)
                //{
                //}
                foreach (int nextNode in edges[currentNode])
                {
                    if (marks[nextNode])
                        return true;
                    marks[nextNode] = true;
                    queue.Enqueue(nextNode);
                }
            }
            return false;
        }
    }

}
