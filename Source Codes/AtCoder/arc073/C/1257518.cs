using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static IO io = new IO();

        static void Main(string[] args)
        {
            io.Read();
            int N = io.Int();
            List<Item> items = new List<Item>();
            for (int i = 0; i < N; ++i)
            {
                io.ReadSplit();
                Item item = new Item();
                item.x = io.Int();
                item.y = io.Int();
                if (item.y < item.x)
                {
                    item.Swap_xy();
                }
                items.Add(item);
            }
            items = items.OrderBy(item => item.x).ToList();

            int maxR = items.Max(item => item.y);
            int minR = items.Min(item => item.y);
            int maxB = items[items.Count - 1].x;
            int minB = items[0].x;
            long solution1 = (long)(maxR - minR) * (maxB - minB);

            minR = minB;
            int minBfromR = int.MaxValue;
            int min_difference_maxBminB = int.MaxValue;
            for (int i = 0; i < items.Count - 1; ++i)
            {
                maxB = Math.Max(maxB, items[i].y);
                minBfromR = Math.Min(minBfromR, items[i].y);
                minB = Math.Min(minBfromR, items[i + 1].x);
                min_difference_maxBminB = Math.Min(min_difference_maxBminB, maxB - minB);
            }
            long solution2 = (long)(maxR - minR) * min_difference_maxBminB;

            io.WriteLine(Math.Min(solution1, solution2).ToString());
        }
    }
    class Item
    {
        public int x;
        public int y;
        public void Swap_xy()
        {
            int tmp = this.x;
            this.x = this.y;
            this.y = tmp;
        }
    }
    class IO
    {
        private string[] _Inputs;
        private int _Index;
        public void Read()
        {
            _Inputs = new string[1];
            _Inputs[0] = Console.ReadLine();
            _Index = 0;
        }
        public void ReadSplit()
        {
            _Inputs = Console.ReadLine().Split(' ');
            _Index = 0;
        }
        public string String()
        {
            return _Inputs[_Index++];
        }
        public string[] String(int xCount)
        {
            string[] rv = new string[xCount];
            Array.Copy(_Inputs, _Index, rv, 0, xCount);
            _Index += xCount;
            return rv;
        }
        public int Int()
        {
            return int.Parse(_Inputs[_Index++]);
        }
        public int[] Int(int xCount)
        {
            int[] rv = new int[xCount];
            for (int i = 0; i < xCount; ++i)
            {
                rv[i] = int.Parse(_Inputs[_Index++]);
            }
            return rv;
        }
        public long Long()
        {
            return long.Parse(_Inputs[_Index++]);
        }
        public long[] Long(int xCount)
        {
            long[] rv = new long[xCount];
            for (int i = 0; i < xCount; ++i)
            {
                rv[i] = long.Parse(_Inputs[_Index++]);
            }
            return rv;
        }
        public void Write(string xStr)
        {
            Console.Write(xStr);
        }
        public void WriteLine(string xStr)
        {
            Console.WriteLine(xStr);
        }
    }
}