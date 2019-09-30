using static System.Console;
using static System.Convert;
class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var num1 = ToInt32(input[0]);
        var dif = ToInt32(input[1]);
        var mod = ToInt32(input[2]);
        var result = "NO";
        for(var i = 1; i < num1*dif; i++)
        {
            if (i*num1 % dif == mod)
            {
                result = "YES";break;
            }
        }
        WriteLine(result);
    }
}