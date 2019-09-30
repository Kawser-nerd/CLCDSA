using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input1 = ReadLine().Split(' ');
        var input2 = ReadLine().Split(' ');
        var height1 = ToInt32(input1[0]);
        var width1 = ToInt32(input1[1]);
        var height2 = ToInt32(input2[0]);
        var width2 = ToInt32(input2[1]);

        if (height1 == height2 || height1 == width2 || width1 == height2 || width1 == width2) WriteLine("YES");
        else WriteLine("NO");
    }
}