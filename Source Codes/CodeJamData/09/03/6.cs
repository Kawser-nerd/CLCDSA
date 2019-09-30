using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Program
    {
        public static void Main(string[] args)
        {
            string filePath = @"C:\C-large.in";

            string target = "welcome to code jam";
            char[] distinctChars = target.Distinct().OrderBy(c => c).ToArray();
            string[] strings = null;

            using (StreamReader reader = new StreamReader(filePath))
            {
                int N = int.Parse(reader.ReadLine());
                strings = new string[N];
                for (int i = 0; i < N; i++)
                    strings[i] = new string(reader.ReadLine().Where(c => distinctChars.Contains(c)).ToArray());
            }

            long[] results = strings.Select(s => Subsequences(target, s)).ToArray();

            using (StreamWriter writer = new StreamWriter(@"C:\result.txt"))
            {
                for(int i = 0; i < results.Length; i++)
                    writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, results[i].ToString().PadLeft(4, '0')));
            }
        }

        public static long Subsequences(string target, string source)
        {
            int[] currentState = new int[target.Length + 1];
            currentState[0] = 1;
            return Subsequences(target, source, currentState, 0);
        }

        public static long Subsequences(string target, string source, int[] currentState, int sourceIndex)
        {
            if (source.Length == 0) return 0;

            char thisLetter = source[sourceIndex];

            for (int i = 0; i < target.Length; i++)
                if (target[i] == thisLetter)
                    currentState[i + 1] = currentState[i + 1] % 10000 + currentState[i] % 10000;

            if (sourceIndex == source.Length - 1)
                return currentState[target.Length] % 10000;
            else
                return Subsequences(target, source, currentState, sourceIndex + 1);
        }
    }
}
