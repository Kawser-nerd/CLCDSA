using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var length = ToInt32(ReadLine());
        var str = ReadLine();
        var x = 0;
        var result = 0;
        for(var i = 0; i < length; i++)
        {
            switch (str.Substring(i, 1))
            {
                case "I":
                    x++;
                    break;
                case "D":
                    x--;
                    break;
            }
            if (result < x) result = x;
        }
        WriteLine(result);
    }
}