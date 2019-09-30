using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var min = ToInt32(input[0]);
        var max = ToInt32(input[1]);
        var num = ToInt32(ReadLine());
        var times = new int[num];

        for(var i = 0; i < num; i++)
        {
            times[i] = ToInt32(ReadLine());
        }
        
        for(var i = 0; i < num; i++)
        {
            if (min > times[i]) WriteLine(min - times[i]);
            else if (max < times[i]) WriteLine(-1);
            else WriteLine(0);
        }
    }
}