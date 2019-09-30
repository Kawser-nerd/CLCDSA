using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows;
using System.Diagnostics;

namespace c
{
    class Program
    {
        static StreamReader fin;
        static StreamWriter fout;
        static List<int> ans;
        static int[,] e;
        static string names = "NROYGBV";
        static void dfs(int v) {
            for (int i = 1; i <= 6; i++)
                if (e[v, i] > 0) {
                    e[v, i]--;
                    dfs(i);
                    ans.Add(v);
                } 
        }

        static void Solve(int index) {
            string[] str = fin.ReadLine().Split(' ');
            int[] arr = new int[7];
            int start = -1;
            for (int i = 0; i < 7; i++) {
                arr[i] = int.Parse(str[i]);
                if (arr[i] > 0) start = i;
            }
            int[] initcnt = new int[7];
            Array.Copy(arr, initcnt, 7);
            e = new int[7, 7];


            fout.Write("Case #{0}: ", index);
            if ((arr[1] < arr[4]) || (arr[3] < arr[6]) || (arr[5] < arr[2])) {
                fout.WriteLine("IMPOSSIBLE");
                return;
            }

            e[4, 1] = e[1, 4] = arr[4];
            e[6, 3] = e[3, 6] = arr[6];
            e[2, 5] = e[5, 2] = arr[2];
            arr[1] -= arr[4];
            arr[3] -= arr[6];
            arr[5] -= arr[2];

            bool impos = ((arr[1] > arr[3] + arr[5]) || (arr[3] > arr[1] + arr[5]) || (arr[5] > arr[1] + arr[3]));
            bool imp2 = ((arr[1] > 0) && (arr[3] > 0) && (arr[5] > 0));

            int last = -1, begin = 1;
            while (arr[1] + arr[3] + arr[5] > 0) {
                int cur = -1, cnt = -1;
                for (int id = begin; id <= begin + 4; id += 2) {;
                    int rid = (id % 6);
                    if (arr[rid] == 0) continue;
                    if (rid == last) continue;
                    if (cnt < arr[rid]) {
                        cnt = arr[rid];
                        cur = rid;
                    }
                }
                if (cur == -1) {
                    Debug.Assert(impos);
                    fout.WriteLine("IMPOSSIBLE");
                    return;
                }
                if (last == -1) begin = cur;
                else e[last, cur]++;
                arr[cur]--;
                last = cur;
            }

            if (last == begin) {
                Debug.Assert(impos);
                fout.WriteLine("IMPOSSIBLE");
                return;
            }

            if (last != -1) e[last, begin]++;

            ans = new List<int>();
            dfs(start);

            if (ans.Count != arr[0]) {
                Debug.Assert(impos || (!imp2));
                fout.WriteLine("IMPOSSIBLE");
            } else {
                for (int i = 0; i < arr[0]; i++) {
                    fout.Write(names[ans[i]]);
                    initcnt[ans[i]]--;
                    initcnt[0]--;
                    if (ans[i] == ans[(i + 1) % arr[0]]) {
                        Debug.Assert(false);
                    }
                }
                for (int i = 0; i < 7; i++)
                    Debug.Assert(initcnt[i] == 0);
                fout.WriteLine();
            }
        }

        static void Main(string[] args) {
            fin = File.OpenText("input.txt");
            fout = File.CreateText("output.txt");
            int n = int.Parse(fin.ReadLine());
            for (int i = 0; i < n; i++)
                Solve(i + 1);
            fin.Close();
            fout.Close();
        }
    }
}
