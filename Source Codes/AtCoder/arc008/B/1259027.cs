using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main(string[] args)
    {
        int[] n = Read.Ints();
        string a1 = Console.ReadLine();
        string b1 = Console.ReadLine();
        int[] a = new int[26];
        int[] b = new int[26];
        for (int i = 0; i < n[0]; i++) { a[a1[i] - 'A']++; }
        for (int i = 0; i < n[1]; i++) { b[b1[i] - 'A']++; }
        int max = 0;
        bool flag = uso();
        for (int i = 0; i < 26; i++)
        {
            if (!flag)
            {
                if (b[i] == 0 && a[i] > 0)
                {
                    Console.WriteLine(-1);
                    break;
                }
                else if (a[i] == 0 && b[i] == 0) { }
                else if (a[i] % b[i] == 0) { max = Math.Max(a[i] / b[i], max); }
              
                else { max = Math.Max(a[i] / b[i] + 1, max); }
            }
            if (i == 25)
            {
                Console.WriteLine(max);
            }
        }    Console.ReadLine();
        
    }
    public static Boolean uso() { return false; }
    public static bool IsPrime(long n)
    {
        if (n < 2) return false;
        if (n == 2) return true;

        for (int i = 2; i < n; i++)
        {
            if (n % i == 0) return false;
        }
        return true;
    }

}
public static class Read
{
    public static void outl(string n = "") { Console.WriteLine(n); return; }
    public static int Int()
    {
        return int.Parse(Console.ReadLine());
    }
    public static int[] Ints()
    {
        return Console.ReadLine().Split().Select(int.Parse).ToArray();
    }
    public static string Str() { return Console.ReadLine(); }
    public static string[] Strs() { return Console.ReadLine().Split(); }
}