using System.Linq;
using static System.Console;

class Program
{
    static string Cin()
    {
        string result = "";
        while (true)
        {
            int tmp0 = Read();
            if (tmp0 < 0)
                break;
            var tmp = (char)tmp0;
            if (!string.IsNullOrWhiteSpace(tmp + ""))
                result += tmp;
            else if (tmp != '\r')
                break;
        }
        return result;
    }

    static void Main()
    {
        int n = int.Parse(Cin());
        int x = int.Parse(Cin());

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int ai = int.Parse(Cin());
            ans += x % 2 * ai;
            x /= 2;
        }
        WriteLine(ans);
    }
}