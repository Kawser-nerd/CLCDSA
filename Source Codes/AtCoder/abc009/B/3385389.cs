using static System.Console;

class Program
{
    static void Main()
    {
        var N = int.Parse(ReadLine());
        var first = 0;
        var second = 0;

        for (var i = 0; i < N; i++)
        {
            var Ai = int.Parse(ReadLine());

            if (Ai > first)
            {
                second = first;
                first = Ai;
            }
            else if (Ai > second && Ai != first)
                second = Ai;
        }
        WriteLine(second);
    }
}