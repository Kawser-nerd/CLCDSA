using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public Program()
    {
        int n = int.Parse(Console.ReadLine());
        int[] cards = Enumerable.Range(1, 6).ToArray();
        foreach(int i in Enumerable.Range(0, n % 30))
        {
            int a = i % 5;
            int temp = cards[a];
            cards[a] = cards[a + 1];
            cards[a + 1] = temp;
        }
        Console.WriteLine(string.Join("", cards));
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}