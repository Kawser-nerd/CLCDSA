using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        var n = int.Parse(ReadLine());

        int[] a = { 0, 0, 1 };

        for (var i = 3; i < n; i++)
        {
            a[i % 3] = a.Sum() % 10007;
        }

        WriteLine(a[(n - 1) % 3]);
    }
}