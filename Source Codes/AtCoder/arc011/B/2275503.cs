using System;

class Program
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        string[] a = Console.ReadLine().Split();
        bool start = false;
        for (int i = 0; i < n; i++)
        {
            bool f = false;

            for (int k = 0; k < a[i].Length; k++)
            {
                if (char.IsLetter(a[i], k))
                {
                    char s = char.ToLower(a[i][k]);
                    if (s == 'b' || s == 'c') { if (!f && start) { Console.Write(" "); } Console.Write("1"); f = true;start = true; }
                    else if (s == 't' || s == 'j') { if (!f && start) { Console.Write(" "); } Console.Write("3"); f = true; start = true; }
                    else if (s == 'd' || s == 'w') { if (!f && start) { Console.Write(" "); } Console.Write("2"); f = true; start = true; }
                    else if (s == 'l' || s == 'v') { if (!f && start) { Console.Write(" "); } Console.Write('5'); f = true; start = true; }
                    else if (s == 'f' || s == 'q') { if (!f && start) { Console.Write(" "); } Console.Write('4'); f = true; start = true; }
                    else if (s == 's' || s == 'x') { if (!f && start) { Console.Write(" "); } Console.Write('6'); f = true; start = true; }
                    else if (s == 'p' || s == 'm') { if (!f && start) { Console.Write(" "); } Console.Write("7"); f = true; start = true; }
                    else if (s == 'h' || s == 'k') { if (!f && start) { Console.Write(" "); } Console.Write("8"); f = true; start = true; }
                    else if (s == 'n' || s == 'g') { if (!f && start) { Console.Write(" "); } Console.Write("9"); f = true; start = true; }
                    else if (s == 'z' || s == 'r') { if (!f && start) { Console.Write(" "); } Console.Write("0"); f = true; start = true; }
                }
            }
            /* if (f && i != n - 1)
             {
                 Console.Write(" ");
             }*/
        }
        Console.WriteLine();
        Console.ReadLine();
    }
}