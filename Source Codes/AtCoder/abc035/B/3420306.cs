using static System.Console;
using static System.Math;

class Program
{
    static void Main()
    {
        string s = ReadLine();
        int t = int.Parse(ReadLine());
        WriteLine(Calc(s)[t - 1]);
    }

    static int[] Calc(string S)
    {
        int x, y, t;
        x = y = t = 0;

        foreach (char v in S)
        {
            switch (v)
            {
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
                default:
                    t++;
                    break;
            }
        }
        int _base = Abs(x) + Abs(y);
        int maxResult = _base + t;
        int tmp = _base - t;
        int minResult;
        if (tmp >= 0)
            minResult = tmp;
        else
            minResult = Abs(tmp % 2);

        return new int[] { maxResult, minResult };
    }
}