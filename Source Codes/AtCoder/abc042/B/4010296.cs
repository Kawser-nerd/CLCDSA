using System;

class Program {
    public static void Main() {
        var s = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        var strs = new string[s[0]];
        for (int i = 0; i < s[0]; i++) {
            strs[i] = Console.ReadLine();
        }

        Array.Sort(strs);
        Console.WriteLine(string.Join("", strs));
    }
}