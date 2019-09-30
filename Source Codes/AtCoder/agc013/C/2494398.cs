using System;
using System.IO;
using System.Linq;

namespace AGC013
{
    class C
    {
        static void Main(string[] args)
        {
            var NLT = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var N = NLT[0];
            var L = NLT[1];
            var T = NLT[2];
            var AntPos = new int[N];
            var StdDir = 1;
            var XW = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var X = XW[0];
            var W = XW[1];
            AntPos[0] = X;
            StdDir = W == 1 ? 1 : -1;
            var collision = 0;
            for (int i = 1; i < AntPos.Length; i++)
            {
                XW = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                X = XW[0];
                W = XW[1] == 1 ? 1 : -1;
                AntPos[i] = ((W == 1 ? X + T : X - T) % L + L) % L;
                if (W != StdDir)
                {
                    var diff = Math.Abs(X - AntPos[0]);
                    diff = StdDir == 1 ? diff : L - diff;
                    collision += (2 * T - diff) >= 0 ? (2 * T - diff) / L + 1 : 0;
                }
            }
            AntPos[0] = ((StdDir == 1 ? AntPos[0] + T : AntPos[0] - T) % L + L) % L;
            var StdPos = AntPos[0];

            Array.Sort(AntPos);

            var offset = BinarySearch(AntPos, StdPos);
            if (StdDir == -1 && AntPos[(offset - 1 + N) % N] == StdPos) offset--;

            var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            Console.SetOut(sw);

            for (int i = 0; i < AntPos.Length; i++)
            {
                var index = ((i + offset - StdDir * collision) % N + N) % N;
                Console.WriteLine(AntPos[index]);
            }

            Console.Out.Flush();
        }

        public static int BinarySearch<T>(T[] array, T target) where T : IComparable<T>
        {
            int min = 0;
            int max = array.Length - 1;

            while (true)
            {
                if (max < min) return -1;
                int mid = min + (max - min) / 2;
                switch (target.CompareTo(array[mid]))
                {
                    case -1:
                        max = mid - 1;
                        break;
                    case 1:
                        min = mid + 1;
                        break;
                    case 0:
                        return mid;
                }
            }
        }
    }
}