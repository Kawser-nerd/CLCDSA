class a
{
    static int rev(int x)
    {
        var ch = x.ToString().ToCharArray();
        Array.Reverse(ch);
        return int.Parse(new string(ch));
    }
    static void Main(string[] args)
    {
        var s = Enumerable.Range(0, 1000001).ToArray();
        for (var i = 1; i < 1000001; i++)
        {
            s[i] = Math.Min(s[i], s[i - 1] + 1);
            var r = rev(i);
            s[r] = Math.Min(s[i]+1, s[r]);
        }
        var t = int.Parse(Console.ReadLine());
        for (var c = 1; c <= t; c++)
        {
            var n = int.Parse(Console.ReadLine());
            Console.WriteLine("Case #{0}: {1}", c, s[n]);
        }
    }
}
