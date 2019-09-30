using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC078D_2 {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            List<int>[] graph = new List<int>[N];
            for (int i = 0; i < N; i++) {
                graph[i] = new List<int>();
            }
            for (int i = 0; i < N - 1; i++) {
                int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                graph[input[0] - 1].Add(input[1] - 1);
                graph[input[1] - 1].Add(input[0] - 1);
            }
            int[] bnums = Enumerable.Repeat(-1, N).ToArray();
            int[] wnums = Enumerable.Repeat(-1, N).ToArray();
            Queue<int> bqueue = new Queue<int>();
            Queue<int> wqueue = new Queue<int>();
            bnums[0] = 0;
            bqueue.Enqueue(0);
            wnums[N - 1] = 0;
            wqueue.Enqueue(N - 1);
            while (bqueue.Count != 0 || wqueue.Count != 0) {
                if (bqueue.Count != 0) {
                    int n = bqueue.Dequeue();
                    foreach (int i in graph[n]) {
                        if (bnums[i] == -1) {
                            bnums[i] = bnums[n] + 1;
                            bqueue.Enqueue(i);
                        }
                    }
                }
                if (wqueue.Count != 0) {
                    int n = wqueue.Dequeue();
                    foreach (int i in graph[n]) {
                        if (wnums[i] == -1) {
                            wnums[i] = wnums[n] + 1;
                            wqueue.Enqueue(i);
                        }
                    }
                }
            }
            int bcount = 0;
            int wcount = 0;
            for (int i = 0; i < N; i++){
                if(bnums[i] <= wnums[i]) {
                    bcount++;
                } else {
                    wcount++;
                }
            }
            bool ok = true;
            if (bcount <= wcount) {
                ok = false;
            }
            if (ok) {
                Console.WriteLine("Fennec");
            } else {
                Console.WriteLine("Snuke");
            }
        }
    }
}