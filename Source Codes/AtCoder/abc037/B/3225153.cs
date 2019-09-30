using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var row = new int[ToInt32(input[0])];
        var num = ToInt32(input[1]);
        for(var i = 0; i < num; i++)
        {
            var input2 = ReadLine().Split(' ');
            var start = ToInt32(input2[0]);
            var end = ToInt32(input2[1]);
            var fig = ToInt32(input2[2]);
            for(var j = start - 1; j < end; j++)
            {
                row[j] = fig;
            }
        }
        for(var i = 0; i < row.Length; i++)
        {
            WriteLine(row[i]);
        }
    }
}