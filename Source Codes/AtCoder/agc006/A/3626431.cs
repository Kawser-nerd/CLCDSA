using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var s = ReadLine();
        var t = ReadLine();
        var pre = -1;
        for(var i = 0; i < num; i++)
            if (t.Substring(0, num - i) == s.Substring(i))
            {
                pre = i;
                break;
            }
        if (pre == -1) pre = num;
        WriteLine(num+pre);
    }
}