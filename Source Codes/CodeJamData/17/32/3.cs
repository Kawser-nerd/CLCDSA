using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1CProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            var t = int.Parse(Console.ReadLine());
            for (var it = 1; it <= t; it++)
            {
                var parts = Console.ReadLine().Split(' ');
                var ac = int.Parse(parts[0]);
                var aj = int.Parse(parts[1]);
                var c = new int[ac];
                var d = new int[ac];
                var j = new int[aj];
                var k = new int[aj];
                for (var i = 0; i < ac; i++)
                {
                    parts = Console.ReadLine().Split(' ');
                    c[i] = int.Parse(parts[0]);
                    d[i] = int.Parse(parts[1]);
                }
                for (var i = 0; i < aj; i++)
                {
                    parts = Console.ReadLine().Split(' ');
                    j[i] = int.Parse(parts[0]);
                    k[i] = int.Parse(parts[1]);
                }

                Console.WriteLine($"Case #{it}: {Solve(c, d, j, k)}");
            }
        }

        private static int Solve(int[] ci, int[] di, int[] ji, int[] ki)
        {
            var original = new List<Interval>();
            for (var i = 0; i < ci.Length; i++)
            {
                original.Add(new Interval { Start = ci[i], End = di[i], Type = 1 });
            }
            for (var i = 0; i < ji.Length; i++)
            {
                original.Add(new Interval { Start = ji[i], End = ki[i], Type = 2 });
            }

            original = original.OrderBy(interval => interval.Start).ToList();

            DebugIntervals(original, "Original");

            var offset = original[0].Start;
            foreach (var interval in original)
            {
                interval.Start -= offset;
                interval.End -= offset;
            }

            DebugIntervals(original, "Original / shift");

            var withUndefined = new List<Interval>();
            withUndefined.Add(original[0]);

            for (var i = 1; i < original.Count; i++)
            {
                if (withUndefined[withUndefined.Count - 1].End != original[i].Start)
                {
                    withUndefined.Add(new Interval { Start = withUndefined[withUndefined.Count - 1].End, End = original[i].Start, Type = 0 });
                }

                withUndefined.Add(original[i]);
            }

            if (withUndefined[withUndefined.Count - 1].End != 1440)
            {
                withUndefined.Add(new Interval { Start = withUndefined[withUndefined.Count - 1].End, End = 1440, Type = 0 });
            }

            for (var i = 0; i < withUndefined.Count; i++)
            {
                if (withUndefined[i].Type == 0)
                {
                    var left = (withUndefined.Count + i - 1) % withUndefined.Count;
                    var right = (i + 1) % withUndefined.Count;
                    if (withUndefined[left].Type == withUndefined[right].Type)
                    {
                        withUndefined[i].Type = 10 + withUndefined[left].Type;
                    }
                }
            }

            DebugIntervals(withUndefined, "withUndefined");

            var linkedList = new LinkedList<Interval>(withUndefined);
            while (true)
            {
                var sum1 = linkedList.Where(interval => interval.Type % 10 == 1).Sum(interval => interval.Length);
                var sum2 = linkedList.Where(interval => interval.Type % 10 == 2).Sum(interval => interval.Length);
                DebugIntervals(linkedList, $"sum1={sum1}, sum2={sum2}");
                if (sum1 > 720)
                {
                    var nodeToSplit = GetAllNodes(linkedList).Where(node => node.Value.Type == 11).OrderByDescending(node => node.Value.Length).First();
                    linkedList.AddBefore(nodeToSplit, new Interval { Start = nodeToSplit.Value.Start, End = nodeToSplit.Value.Start + 1, Type = 2 });
                    if (nodeToSplit.Value.Length > 1)
                    {
                        linkedList.AddBefore(nodeToSplit, new Interval { Start = nodeToSplit.Value.Start + 1, End = nodeToSplit.Value.End, Type = 0 });
                    }
                    linkedList.Remove(nodeToSplit);
                }
                else if (sum2 > 720)
                {
                    var nodeToSplit = GetAllNodes(linkedList).Where(node => node.Value.Type == 12).OrderByDescending(node => node.Value.Length).First();
                    linkedList.AddBefore(nodeToSplit, new Interval { Start = nodeToSplit.Value.Start, End = nodeToSplit.Value.Start + 1, Type = 1 });
                    if (nodeToSplit.Value.Length > 1)
                    {
                        linkedList.AddBefore(nodeToSplit, new Interval { Start = nodeToSplit.Value.Start + 1, End = nodeToSplit.Value.End, Type = 0 });
                    }
                    linkedList.Remove(nodeToSplit);
                }
                else
                {
                    break;
                }
            }

            DebugIntervals(linkedList, "linked list after replacements");
            var finalIntervals = linkedList.Where(interval => interval.Type != 0).Select(interval => interval.Type % 10).ToArray();
            var currentType = finalIntervals[0];
            var result = 0;
            for (var i = 1; i < finalIntervals.Length; i++)
            {
                if (finalIntervals[i] != currentType)
                {
                    currentType = finalIntervals[i];
                    result++;
                }
            }

            if (finalIntervals[0] != currentType)
            {
                currentType = finalIntervals[0];
                result++;
            }

            return result;
        }

        private static void DebugIntervals(IEnumerable<Interval> intervals, string message)
        {
            /*
            Console.WriteLine(message);

            foreach (var interval in intervals)
            {
                Console.WriteLine($"{interval.Start:0000}->{interval.End:0000}: {interval.Type}");
            }*/
        }

        private static IEnumerable<LinkedListNode<T>> GetAllNodes<T>(LinkedList<T> linkedList)
        {
            var currentNode = linkedList.First;
            while (currentNode != null)
            {
                yield return currentNode;
                currentNode = currentNode.Next;
            }
        }

        private class Interval
        {
            public int Start;
            public int End;
            public int Type;

            public int Length => End - Start;

            public Interval Clone()
            {
                return new Interval { Start = Start, End = End, Type = Type };
            }
        }
    }
}
