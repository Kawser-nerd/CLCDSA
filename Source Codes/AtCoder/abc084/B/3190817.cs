using System.Linq;
using static System.Console;
using static System.Int32;
using static System.Math;

class Program
{

    static void Main(string[] args)
    {
        label:
        WriteLine(hoge() ? "Yes" : "No");
    }

    static bool hoge()
    {

        var sp = ReadLine().Split();
        int a = Parse(sp[0]);
        var s = ReadLine();
        for (int i = 0; i < s.Length; ++i)
        {
            if (i == a)
            {
                if (s[i] != '-') return false;
            }
            else
            {
                if (s[i] == '-') return false;
            }
        }
        return true;
    }
}