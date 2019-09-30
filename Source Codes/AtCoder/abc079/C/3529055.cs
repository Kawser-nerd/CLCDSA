using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine();
        var bits = new[] {
        new[] { "+", "+", "+", "+", "-", "-", "-", "-" },
        new[] { "+", "+", "-", "-", "+", "+", "-", "-" },
        new[] { "+", "-", "+", "-", "+", "-", "+", "-" },
        };

        for(var i = 0; i < (int)Pow(2, 3); i++)
        {
            var r = ToInt32(input.Substring(0,1));
            for(var j = 0; j < 3; j++)
            {
                var num = ToInt32(input.Substring(j+1,1));
                if (bits[j][i] == "+") r += num;
                else r -= num;
            }
            if (r == 7)
            {
                input = input.Insert(1, bits[0][i]);
                input = input.Insert(3, bits[1][i]);
                input = input.Insert(5, bits[2][i]);
                WriteLine(input + "=7");
                break;
            }
        }
    }
}