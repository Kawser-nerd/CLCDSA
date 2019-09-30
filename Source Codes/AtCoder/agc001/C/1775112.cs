using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace ConsoleApp1
{
    public class node
    {
        public List<node> connect = new List<node>();
        public int index;
    }
    class Program
    {
        static void Main(string[] args)
        {
            var temp = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
            var n = temp[0];
            var k = temp[1];

            node[] nodes = Enumerable.Range(1, (int)n+1).Select(x => new node { index = x }).ToArray();

            int[] a = new int[n + 1];
            int[] b = new int[n + 1];
            for (int i = 1; i < n; i++)
            {
                var t= Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                a[i] = t[0];
                b[i] = t[1];
                nodes[a[i]].connect.Add(nodes[b[i]]);
                nodes[b[i]].connect.Add(nodes[a[i]]);
            }
            int ans = int.MaxValue;
            if (k%2==0)ans = (int)n - nodes.Select(x => search(x, null, (int)k/2)).Skip(1).Max();
            else
            {
                for (int i = 0; i < n; i++)
                {
                    var q1 = search(nodes[a[i]], nodes[b[i]], (int)(k - 1) / 2);
                    var q2 = search(nodes[b[i]], nodes[a[i]], (int)(k - 1) / 2);
                    var result = (int)n - q1 - q2;
                    if (result < ans) ans = result;
                }
            }
            Console.WriteLine(ans);
        }

        /// <summary>k????????(?????)</summary>
        static int search(node node,node pre, int k)
        {
            if (k == 0) return 1;
            int result = 1;
            foreach (var item in node.connect)
            {
                if (item == pre) continue;
                result += search(item, node, k - 1);
            }
            return result;
        }
    }
}