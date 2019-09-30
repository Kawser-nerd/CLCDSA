using System;
using System.Collections.Generic;
using System.Linq;


namespace AtC
{
    class Program
    {
        static void Main(string[] args)
        {
            var arr = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int N = arr[0], M = arr[1];
            var indexes = new int[N];
            var list = new List<Tuple<int, int, int, int>>();
            for (int i = 0; i < M; i++)
            {
                arr = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                list.Add(Tuple.Create(arr[0] - 1, arr[1], i, 0));
            }

            list.Sort((val1, val2) => val1.Item2 - val2.Item2);
            for (var i = 0; i < list.Count; i++)
            {
                list[i] = Tuple.Create(list[i].Item1 + 1, list[i].Item2, list[i].Item3, ++indexes[list[i].Item1]);
            }

            list.Sort((val1, val2) => val1.Item3 - val2.Item3);
            list.ForEach(val => Console.WriteLine($"{val.Item1:D6}{val.Item4:D6}"));
        }
    }
}