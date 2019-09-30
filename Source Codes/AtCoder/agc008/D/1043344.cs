using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AGC008
{
    public class D
    {
        private const string Yes = "Yes";
        private const string No = "No";
        private void Run()
        {
            var N = int.Parse(Console.ReadLine().Trim());
            var X = Console.ReadLine().Trim().Split().Select(int.Parse)
                .Select(x => x - 1) // to 0-indexed
                .ToArray();

            if (X.Distinct().Count() != X.Length) { goto No; }

            var array = Enumerable.Range(0, N)
                .Select(i => Tuple.Create(X[i], i + 1)) // [index, value]
                .OrderBy(t => t.Item1)
                .ToArray();

            var head = new Queue<int>();
            var rest = new Queue<int>();
            var resArray = new int[N * N];

            foreach (var t in array)
            {
                for (int i = 0; i < t.Item2 - 1; i++)
                {
                    head.Enqueue(t.Item2);
                }
            }

            var used = new bool[N];
            int index = 0;
            for (int i = 0; i < resArray.Length; i++)
            {
                int currentValue;
                if (index < array.Length && i == array[index].Item1)
                {
                    int arrayValue = array[index].Item2;
                    currentValue = arrayValue;
                    for (int j = arrayValue + 1; j <= N; j++)
                    {
                        rest.Enqueue(arrayValue);
                    }
                    used[arrayValue - 1] = true;
                    index++;
                }
                else
                {
                    if (head.Count > 0)
                    {
                        currentValue = head.Dequeue();
                        if (used[currentValue - 1]) { goto No; }
                    }
                    else
                    {
                        if (rest.Count == 0) { goto No; }
                        currentValue = rest.Dequeue();
                    }
                }
                resArray[i] = currentValue;
            }

            Console.WriteLine(Yes);
            Console.WriteLine(string.Join(" ", resArray));
            return;

            No:
            Console.WriteLine(No);
            return;
        }

        public static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new D().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}