using static System.Console;

class Program
{
    static void Main()
    {
        int n = int.Parse(Scan());
        int sum = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            int ai = int.Parse(Scan());
            sum += ai;
            if (ai != 0)
                cnt++;
        }
        WriteLine((sum - 1) / cnt + 1);
    }

    static string Scan()
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