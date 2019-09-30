using static System.Console;
using static System.Convert;
class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var height = ToInt32(input[0]);
        var width = ToInt32(input[1]);
        var strs = new string[height];
        for(var i = 0; i < height; i++)
        {
            strs[i] = $"#{ReadLine()}#";
        }
        var outLine = "";
        for(var i = 0; i < width + 2; i++)
        {
            outLine += "#";
        }
        WriteLine(outLine);
        for(var i = 0; i < height; i++)
        {
            WriteLine(strs[i]);
        }
        WriteLine(outLine);
    }
}