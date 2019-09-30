using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        var S = ReadLine() + '+';
        var ans = 0;
        var flg = false;

        foreach (var i in Enumerable.Range(0, S.Length))
        {
            if (i % 2 == 0 && S[i] == '0')
            {
                flg = true;
            }
            else if (S[i] == '+')
            {
                if (!flg)
                {
                    ans++;
                }
                flg = false;
            }
        }
        WriteLine(ans);
    }
}