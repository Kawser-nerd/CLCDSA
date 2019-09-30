using static System.Console;

class Program
{
    static void Main()
    {
        var tmpA = ReadLine().Split();
        var n = int.Parse(tmpA[0]);
        var q = int.Parse(tmpA[1]);

        var ans = new int[n];

        for (var i = 0; i < q; i++)
        {
            var tmpB = ReadLine().Split();
            var l = int.Parse(tmpB[0]);
            var r = int.Parse(tmpB[1]);
            var t = int.Parse(tmpB[2]);

            for (var j = l; j <= r; j++)
            {
                ans[j - 1] = t;
            }
        }
        foreach (var v in ans)
        {
            WriteLine(v);
        }
    }
}