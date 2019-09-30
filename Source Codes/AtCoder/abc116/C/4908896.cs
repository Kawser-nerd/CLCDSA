using System;
using System.Linq;


namespace AtC
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var h = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            Console.WriteLine(Count(h, 0, N));
        }

        static int Count(int[] arr, int start, int end)
        {
            if (end <= start) return 0;
            int min = int.MaxValue;
            for (int i = start; i < end; i++)
                if (arr[i] < min)
                    min = arr[i];
            for (int i = start; i < end; i++) arr[i] -= min;
            int count = min;
            int indexBuf = start;
            for (int i = start; i <= end; i++)
            {
                if (i == end || arr[i] == 0)
                {
                    count += Count(arr, indexBuf, i);
                    indexBuf = i + 1;
                }
            }

            return count;
        }
    }
}