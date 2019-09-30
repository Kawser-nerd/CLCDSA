using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var s = ToInt32(ReadLine());
        var fig = 1;
        for(var i = 0; i < num; i++)
        {
            if (s + fig <= 2 * fig) fig += s;
            else fig *= 2;
        }
        WriteLine(fig);
    }
}