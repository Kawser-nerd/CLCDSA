using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC073D {
    class Program {
        static void Main(string[] args) {
            int[] NWinput = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = NWinput[0];
            int W = NWinput[1];
            List<int>[] values = new List<int>[4];
            for (int i = 0; i < 4; i++) {
                values[i] = new List<int>();
            }
            int[] firstinput = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int weight = firstinput[0];
            values[0].Add(firstinput[1]);
            for (int i = 0; i < N - 1; i++) {
                int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                values[input[0] - weight].Add(input[1]);
            }
            for (int i = 0; i < 4; i++) {
                values[i].Sort();
                values[i].Reverse();
            }
            List<long>[] valuesums = new List<long>[4];
            for (int i = 0; i < 4; i++) {
                valuesums[i] = new List<long>();
                valuesums[i].Add(0);
                for (int j = 0; j < values[i].Count; j++) {
                    valuesums[i].Add(valuesums[i][j] + values[i][j]);
                }
            }
            long max = 0;
            int div = W / weight;
            for (int i = 0; i < Math.Min(valuesums[0].Count, div + 1); i++) {
                for (int j = 0; j < Math.Min(valuesums[1].Count, div + 1); j++) {
                    for (int k = 0; k < Math.Min(valuesums[2].Count, div + 1); k++) {
                        int l = Math.Min(valuesums[3].Count - 1, div - i - j - k);
                        if (l >= 0 && i * weight + j * (weight + 1) + k * (weight + 2) + l * (weight + 3) <= W) {
                            max = Math.Max(max, valuesums[0][i] + valuesums[1][j] + valuesums[2][k] + valuesums[3][l]);
                        }
                    }
                }
            }
            Console.WriteLine(max);
        }
    }
}