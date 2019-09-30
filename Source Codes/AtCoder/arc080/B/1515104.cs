using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Regular80
{
    public class GridColor
    {
        private int height;
        private int width;
        private int N;
        private int[] nums;
        private int[] sums;
        public GridColor(int height, int width, int N, int[] nums)
        {
            this.height = height;
            this.width = width;
            this.N = N;
            this.nums = nums;
            sums = new int[N];
            for (int i = 0; i < N; i++)
            {
                sums[i] = nums.Take(i+1).Sum();
            }
        }

        public void Run()
        {
            var colorArray = GetColorArray();
            Write(colorArray);

        }
        public int[,] GetColorArray()
        {
            var colorRec = new int[height, width];
            int indicator = 0;
            for (int i = 0; i < height; i++)
            {
                bool isEven = i % 2 == 0;
                int j = isEven ? 0 : width - 1;
                int inc = isEven ? 1 : -1;
                int jStop = isEven ? width : -1;
                while (j != jStop)
                {
                    colorRec[i, j] = Coloring(indicator);
                    indicator++;
                    j += inc;
                }
            }
            return colorRec;
        }
        public int Coloring(int indicator)
        {
            foreach(var n in sums)
            {
                if (indicator < n)
                    return Array.IndexOf(sums, n) + 1;
            }
            return 0;
        }

        public void Write(int[,] colorArray)
        {
            for(int i = 0; i< height; i++)
            {
                for(int j = 0; j< width; j++)
                {
                    if (j < width - 1)
                        Console.Write("{0} ", colorArray[i, j]);
                    else
                        Console.WriteLine("{0}", colorArray[i, j]);
                }
            }
        }

    }


    class Program
    {
        static void Main(string[] args)
        {
            var gridLength = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var height = gridLength[0];
            var width = gridLength[1];
            var N = int.Parse(Console.ReadLine());
            var nums = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            if (nums.Count() != N)
                throw new ArgumentException("");

            var gridColor = new GridColor(height, width, N, nums);
            gridColor.Run();
        }
    }
}