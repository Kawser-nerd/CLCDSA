using static System.Console;
using System.Linq;

class Program
{
    static int calc(int n)
    {
        var result = 0;
        while (n % 2 == 0 || n % 3 == 2)
        {
            n--;
            result++;
        }
        return result;
    }

    static void Main()
    {
        var n = int.Parse(ReadLine());
        var cnt = 0;

        var a = ReadLine().Split(' ').Select(int.Parse).ToArray();

        for (var i = 0; i < n; i++)
            cnt += calc(a[i]);

        WriteLine(cnt);
    }
}