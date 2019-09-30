using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        int N = int.Parse(ReadLine());
        var hms = new List<int>();

        for (int i = 0; i < 3; i++)
        {
            hms.Add(N % 60);
            N /= 60;
        }
        WriteLine(string.Join(":", Enumerable.Reverse(
            hms.Select((int x) => x.ToString("00")))));
    }
}