using System;
class Program
{
    static void Main(string[] args)
    {
        // ?
        string ans = string.Empty;

        // ??
        string inp = Console.ReadLine();

        DateTime dt = DateTime.ParseExact(inp, "yyyy/MM/dd", null);

        if (dt <= new DateTime(2019, 4, 30))
        {
            ans = "Heisei";
        }
        else
        {
            ans = "TBD";
        }

        //??
        Console.WriteLine(ans);
    }
}