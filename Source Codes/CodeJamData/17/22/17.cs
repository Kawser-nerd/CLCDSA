using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class StableUnicorns
    {
        static SortedList<char, char[]> possibleNext = new SortedList<char, char[]> {
            ['R'] = new[] { 'G', 'Y', 'B' },
            ['Y'] = new[] { 'V', 'B', 'R' },
            ['B'] = new[] { 'O', 'R', 'Y' },
            ['G'] = new[] { 'R' },
            ['V'] = new[] { 'Y' },
            ['O'] = new[] { 'B' },
        };
        const string indexToColor = "ROYGBV";
        static int ColorToIndex(char color) => indexToColor.IndexOf(color);
        public static string Solve(TextReader reader)
        {
            int[] stallsColorings = PonyExpress.ReadIntArray(reader);
            int stalls = stallsColorings[0];
            int[] initialColorings = stallsColorings.Skip(1).ToArray();
            for (int startCharIndex = 0; startCharIndex < initialColorings.Length; startCharIndex++) {
                int[] coloring = (int[])initialColorings.Clone();
                var result = Coloring(stalls, coloring, startCharIndex);
                if (result != null)
                    return result;
            }

            return "IMPOSSIBLE";
        }

        static string Coloring(int stalls, int[] coloring, int startCharIndex)
        {
            var result = new StringBuilder();
            if (coloring[startCharIndex] == 0)
                return null;

            char startChar = indexToColor[startCharIndex];
            char nextChar = startChar;
            for (int consumed = 0; consumed < stalls; consumed++) {
                coloring[ColorToIndex(nextChar)]--;
                result.Append(nextChar);
                if (consumed + 1 == stalls) {
                    if (possibleNext[startChar].Contains(nextChar))
                        return result.ToString();
                    else
                        return null;
                }

                nextChar = possibleNext[nextChar]
                    .OrderByDescending(c => coloring[ColorToIndex(c)])
                    .FirstOrDefault(c => coloring[ColorToIndex(c)] > 0);
                if (nextChar == default(char))
                    return null;
            }
            return result.ToString();
        }
    }
}
