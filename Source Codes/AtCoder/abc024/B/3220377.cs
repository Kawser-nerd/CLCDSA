using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var person = ToInt32(input[0]);
        var openTime = ToInt32(input[1]);
        var times = new int[person];

        var result = 0;
        for(var i = 0; i < person; i++)
        {
            times[i] = ToInt32(ReadLine());
        }

        for(var i = 0; i < person; i++)
        {
            if (i == 0) { result += openTime;continue; }
            if (times[i] - times[i - 1] < openTime) result += times[i] - times[i - 1];
            else result += openTime;
        }

        WriteLine(result);

    }
}