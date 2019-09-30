using static System.Console;

class Program
{
    static void Main()
    {
        string a = Scan();
        string b = Scan();

        WriteLine(int.Parse(a + b) * 2);
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