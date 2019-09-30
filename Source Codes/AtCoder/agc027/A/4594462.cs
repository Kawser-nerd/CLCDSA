using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = s[0];
        int x = s[1];
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Array.Sort(a);
        int count = 0;
        for(int i = 0; i<n; i ++) {
            x -= a[i];
            if (x>=0) count ++;
            else break;
        }
        if (x>0) count --;
        Console.WriteLine(count);
    }
}