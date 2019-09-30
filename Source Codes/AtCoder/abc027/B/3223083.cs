using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var input = ReadLine().Split(' ');
        var personFig = new int[num];
        var sum = 0;
        for(var i = 0; i < num; i++)
        {
            personFig[i] = ToInt32(input[i]);
            sum += personFig[i];
        }

        if (sum / num != (double)sum / num) WriteLine(-1);
        else
        {
            var ave = sum / num;
            var dif = 0;
            var result = 0;
            for (var i = 0; i < num; i++)
            {
                if (personFig[i] != ave) dif += personFig[i] - ave;
                if (dif != 0) result++;
               
            }

            WriteLine(result);
        }
    }
}