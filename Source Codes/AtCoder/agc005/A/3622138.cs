using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var s = 0;
        var result = 0;
        for(var i = 0; i < str.Length; i++)
        {
            if (str[i] == 'S') s++;
            else
            {
                if (s == 0) continue;
                else { s--; result++; }
            }
        }
        WriteLine(str.Length-2*result);
    }
}