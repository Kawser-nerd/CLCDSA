using static System.Console;

class Program
{
    static void Main()
    {
        int l = NextInt();
        int h = NextInt();
        int n = NextInt();

        var ans = new int[n];

        for (var i = 0; i < ans.Length; i++)
        {
            ans[i] = Judge(l, h);
        }
        WriteLine(string.Join("\n", ans));
    }

    static int Judge(int L, int H)
    {
        int a = NextInt();

        if (L <= a && a <= H) return 0;
        if (a < L) return L - a;
        return -1;
    }

    static int NextInt()
    {
        return int.Parse(NextString());
    }

    static string NextString()
    {
        var result = "";
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