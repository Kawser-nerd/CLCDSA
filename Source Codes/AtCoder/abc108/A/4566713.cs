using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int k = int.Parse(Console.ReadLine());
        int[] n = new int[k];
        for (int i = 0; i < k; i ++) n[i] = i+1;
        Console.WriteLine(n.Where(x=>x%2==1).Count() * n.Where(x=>x%2==0).Count());
    }
}