using static System.Console;
using System.Linq;

class Program
{
    static void Main()
    {
        int N = int.Parse(ReadLine());
        int[] hms = { 0, 0, 0 };

        for (int i = hms.Length - 1; i >= 0; i--)
        {
            hms[i] = N % 60;
            N /= 60;
        }
        WriteLine(string.Join(":", hms.Select((int x) => x.ToString("00"))));
    }
}