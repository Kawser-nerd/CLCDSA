using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int h = s[0];
        int w = s[1];
        List<string> a = new List<string>();
        for (int i = 0; i < h; i ++) {
            string str = Console.ReadLine();
            if (str.Contains("#")) a.Add(str);
        }
        int l = a.Count();
        for (int i = 0; i < a[0].Length; i ++) {
            for (int j = 0; j < l; j ++) {
                if (a[j][i]=='#') break;
                if (j == l-1) {
                    for (int k = 0; k < l; k ++) {
                        a[k] = a[k].Remove(i,1);
                    }
                    i --;
                }
            }
        }
        foreach(string i in a) Console.WriteLine(i);
    }
}