using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var Lucas = new ulong[num+1];
        Lucas[0] = 2;
        Lucas[1] = 1;
        for(var i = 2; i <= num; i++)
        {
            Lucas[i] = Lucas[i - 1] + Lucas[i - 2];
        }
        WriteLine(Lucas[num]);
    }
}