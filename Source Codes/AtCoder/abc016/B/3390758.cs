using static System.Console;

class Program
{
    static void Main()
    {
        int a = int.Parse(Scan());
        int b = int.Parse(Scan());
        int c = int.Parse(Scan());
        char ans;

        if (c == a + b && c == a - b)
            ans = '?';
        else if (c == a + b)
            ans = '+';
        else if (c == a - b)
            ans = '-';
        else
            ans = '!';

        WriteLine(ans);
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