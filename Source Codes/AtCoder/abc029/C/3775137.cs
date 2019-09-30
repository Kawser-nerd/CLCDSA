using static System.Console;

class Program
{
    static int n = int.Parse(ReadLine());

    static void Main()
    {
        DFS("");
    }

    static void DFS(string s)
    {
        if (s.Length == n)
        {
            WriteLine(s);
            return;
        }
        foreach (var v in "abc")
        {
            DFS(s + v);
        }
    }
}