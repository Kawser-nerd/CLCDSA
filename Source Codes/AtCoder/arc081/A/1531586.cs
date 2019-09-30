using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/// <summary>
/// http://arc081.contest.atcoder.jp/tasks/arc081_a
/// </summary>
namespace _170821CS_MakeRectangle_Console {
    class Program {
        static void Main(string[] args) {
            //int[] map = { 3, 1, 2, 4, 2, 1 };
            //int[] map = { 1, 2, 3, 4 };
            //int[] map = { 3, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6 };
            //int[] map = Enumerable.Range(0, 100000).Select(x => x / 2).ToArray();
            int n = Convert.ToInt32(Console.ReadLine());
            string input = Console.ReadLine();
            var map = input.Split(' ').Select(x => Convert.ToInt32(x)).ToArray();
            long ans = Solve(map);
            Console.WriteLine(ans);
        }
        private static long Solve(int[] map) {
            var list = map.ToList();
            list.Sort();
            int p = 0;
            long[] ans = { 0, 0 };
            for(int i=list.Count - 1; i > 0; i--) {
                if(list[i] == list[i - 1]) {
                    ans[p++] = list[i--];
                }
                if (p == 2) break;
            }
            return ans[0] * ans[1];
        }
    }
}