using System;
class a
{
    static void Main()




    {
        string[] a = Console.ReadLine().Split();
        for (int i = 0; i < a.Length; i++)
        {
            if (a[i] == "AtCoder") { Console.Write("A"); }
            else if (a[i] == "Right") { Console.Write(">"); }
            else { Console.Write("<"); }
            if (i != a.Length - 1) { Console.Write(" "); } else { Console.WriteLine(); }
        }
    }
}