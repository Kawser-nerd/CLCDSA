using static System.Console;

class Program
{
    const int n = 6;

    static void Main()
    {
        int[] ans = new int[n];
        string s = NextStr();

        foreach (char ch in s)
        {
            ans[ch - 'A']++;
        }

        bool flg = false;
        foreach (int v in ans)
        {
            if (flg) Write(" ");
            Write(v);
            flg = true;
        }
        WriteLine();
    }

    static string NextStr()
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