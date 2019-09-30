using System;
public class PG {
    public static void Main() {
        string r = Console.ReadLine();
        Console.WriteLine(r=="A" ? 1 : r=="B" ? 2 : r=="C" ? 3 : r=="D" ? 4 : 5);
    }
}