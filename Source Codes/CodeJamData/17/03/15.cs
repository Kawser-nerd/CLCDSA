using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem1C
{
    class Program
    {
        static void Main(string[] args)
        {
            var testName = args[0];

            using (var reader = new StreamReader($"{testName}.in"))
            using (var writer = new StreamWriter($"{testName}.out"))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseId = 1; caseId <= count; caseId++)
                {
                    var line = reader.ReadLine().Split(' ').Select(long.Parse).ToArray();

                    var split = Split(line[0], line[1]);

                    writer.WriteLine("Case #{0}: {1} {2}", caseId, split.Item2, split.Item1);
                    writer.Flush();
                }
            }
        }

        public static Tuple<long, long> Split(long n, long k)
        {
            var sets = new SetQueue();

            sets.Push(new SetGroup { Count = 1, Size = n });

            while (sets.Any())
            {
                var set = sets.Pop();

                var min = (set.Size - 1) / 2;
                var max = (set.Size / 2);

                if (k <= set.Count)
                {
                    return Tuple.Create(min, max);
                }

                k -= set.Count;
                sets.Push(new SetGroup { Size = min, Count = set.Count });
                sets.Push(new SetGroup { Size = max, Count = set.Count });
            }

            return Tuple.Create(0L, 0L);
        }
    }

    public class SetQueue
    {
        public List<SetGroup> sets = new List<SetGroup>();

        public void Push(SetGroup setGroup)
        {
            for (int i = 0; i < this.sets.Count; i++)
            {
                if (this.sets[i].Size == setGroup.Size)
                {
                    this.sets[i] = new SetGroup { Size = setGroup.Size, Count = this.sets[i].Count + setGroup.Count };
                    return;
                }

                if (this.sets[i].Size < setGroup.Size)
                {
                    this.sets.Insert(i, setGroup);
                    return;
                }
            }

            this.sets.Add(setGroup);
        }

        public SetGroup Pop()
        {
            var set = this.sets[0];
            this.sets.RemoveAt(0);
            return set;
        }

        public bool Any()
        {
            return this.sets.Count != 0;
        }
    }

    public struct SetGroup
    {
        public long Size;
        public long Count;
    }
}
