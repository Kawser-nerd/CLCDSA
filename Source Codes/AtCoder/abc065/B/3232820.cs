using static System.Console;
using static System.Convert;
class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var road = new int[num];
        for(var i = 0; i < num; i++)
        {
            road[i] = ToInt32(ReadLine());
        }
        var button = 1;
        var isClear = false;
        for(var i = 0; i < num; i++)
        {
            button = road[button-1];
            if (button == 2)
            {
                isClear = true;WriteLine(i+1);break;
            }
        }
        if (!isClear) WriteLine(-1);
    }
}