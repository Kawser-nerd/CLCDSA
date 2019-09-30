using System;
public class Hello{
    public static void Main(){
        var n = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
        Array.Sort(n);
        Console.WriteLine(n[1]);
    }
}