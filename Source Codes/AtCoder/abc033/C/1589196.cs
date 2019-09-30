using System;
using System.Linq;

class Program {
    static void Main() => Console.WriteLine(Console.ReadLine().Split('+').Count(x => !x.Contains('0')));
}