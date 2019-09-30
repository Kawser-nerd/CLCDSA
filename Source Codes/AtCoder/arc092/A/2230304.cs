using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC092_ {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            int[,] APos = new int[2, N];
            int[,] BPos = new int[2, N];
            int[] posRank = new int[2 * N];
            bool[] AMarked = new bool[N];
            for (int i = 0; i < N; i++) {
                int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                APos[0, i] = input[0];
                APos[1, i] = input[1];
                posRank[input[0]] = i;
            }
            for (int i = 0; i < N; i++) {
                int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                BPos[0, i] = input[0];
                BPos[1, i] = input[1];
                posRank[input[0]] = i + N;
            }
            int ans = 0;
            List<int> smallAList = new List<int>();
            for (int i = 0; i < 2 * N; i++) {
                if (posRank[i] < N) {
                    smallAList.Add(posRank[i]);
                } else {
                    int BNum = posRank[i] - N;
                    int max = 3 * N;
                    for (int j = 0; j < smallAList.Count(); j++) {
                        int pos = APos[1, smallAList[j]];
                        bool go = true;
                        if (max != 3 * N) {
                            if (pos < APos[1, max]) {
                                go = false;
                            }
                        }
                        if (go && pos < BPos[1, BNum] && !AMarked[smallAList[j]]) {
                            max = smallAList[j];
                        }
                    }
                    if(max != 3 * N) {
                        ans++;
                        AMarked[max] = true;
                    }
                }
            }
            Console.WriteLine(ans);
        }
    }
}