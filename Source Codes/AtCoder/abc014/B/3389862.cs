using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        int[] tmp = ReadLine().Split(' ').Select(int.Parse).ToArray();
        int[] a = ReadLine().Split(' ').Select(int.Parse).ToArray();
        int n = tmp[0];
        int x = tmp[1];

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += x % 2 * a[i];
            x /= 2;
        }
        WriteLine(ans);
    }
}