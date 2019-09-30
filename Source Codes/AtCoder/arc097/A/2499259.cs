using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC097C_2 {
    class Program {
        static void Main(string[] args) {
            string s = Console.ReadLine();
            int K = int.Parse(Console.ReadLine());
            char[] str = s.ToCharArray();
            int len = s.Length;
            int num = 0;
            for (int i = 0; i < len; i++) {
                num += Math.Max(5, len - i);
            }
            List<string> a = new List<string>();
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < 5; j++) {
                    if (i + j < len) {
                        a.Add(s.Substring(i, j + 1));
                    }
                }
            }
            a = a.Distinct().ToList();
            a.Sort();
            //for (int i = 0; i < a.Count(); i++) {
            //    Console.WriteLine(a[i]);
            //}
            Console.WriteLine(a[K - 1]);
        }
    }
}