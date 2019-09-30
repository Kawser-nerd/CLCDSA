using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var figs = new string[num,num];
        for(var i = 0; i < num; i++)
        {
            var input = ReadLine();
            for(var j = 0; j < num; j++)
            {
                figs[i,j] = input.Substring(j, 1);
            }
        }

        for(var i = 0; i < num; i++)
        {
            var f = new string[num];
            for(var j = 0; j < num; j++)
            {
                f[j] = figs[num - 1 - j,i];
            }
            WriteLine(string.Join("", f));
        }
    }
}