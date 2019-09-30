using System;
using System.Linq;
class c
{
    static void Main()
    {
        var ab = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        Console.WriteLine(ab.Contains(2)?"No":"Yes");
    }
}