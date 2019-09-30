using static System.Console;

class Program
{
    static int sum(int[] a)
    {
        var result = 0;
        for (var i = 0; i < a.Length; i++)
        {
            result += a[i];
        }
        return result;
    }

    static void Main()
    {
        var n = int.Parse(ReadLine());

        int[] a = { 0, 0, 1 };

        for (var i = 3; i < n; i++)
        {
            a[i % 3] = sum(a) % 10007;
        }

        WriteLine(a[(n - 1) % 3]);
    }
}