using System;

class Program
{
    static void Main(string[] args)
    {
        string[] s = Console.ReadLine().Split(' ');
        int dx = int.Parse(s[2]) - int.Parse(s[0]);
        int dy = int.Parse(s[3]) - int.Parse(s[1]);

        String path = new string('U', dy) + new string('R', dx)
                    + new string('D', dy) + new string('L', dx)
                    + 'L' + new string('U', dy + 1) + new string('R', dx + 1) + 'D'
                    + 'R' + new string('D', dy + 1) + new string('L', dx + 1) + 'U';
        Console.WriteLine(path);
    }
}