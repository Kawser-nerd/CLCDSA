using System;
using System.Linq;
 
class Program
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        string[] a1 = new string[n];
        for (int i = 0; i < n; i++)
        {
            string y = Console.ReadLine();
            string s2 = new string(y.Reverse().ToArray()); // olleh
            a1[i] = s2;
        }
        Array.Sort(a1);
        for (int i = 0; i < n; i++)
        {
            string s3 = new string(a1[i].Reverse().ToArray()); // olleh
 
            Console.WriteLine(s3);
        }
        Console.ReadLine();
    }
}