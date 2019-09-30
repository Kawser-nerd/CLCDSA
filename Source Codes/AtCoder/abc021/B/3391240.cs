using static System.Console;

class Program
{
    static void Main()
    {
        var n = nextInt();
        var a = nextInt();
        var b = nextInt();
        var k = nextInt();

        var P = new int[k + 2];
        P[0] = a;
        P[1] = b;

        var ans = "YES";

        for (var i = 0; i < k; i++)
        {
            var Pi = nextInt();
            if (contains(P, Pi))
            {
                ans = "NO";
                break;
            }
            P[i + 2] = Pi;
        }
        WriteLine(ans);
    }

    static bool contains(int[] P, int Pi)
    {
        for (var i = 0; i < P.Length; i++)
        {
            if (P[i] == Pi) return true;
        }

        return false;
    }

    static int nextInt()
    {
        return int.Parse(nextStr());
    }

    static string nextStr()
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
}