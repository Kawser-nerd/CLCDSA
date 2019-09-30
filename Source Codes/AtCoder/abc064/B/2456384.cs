using System;
using System.Linq;
public class Hello{
    public static void Main(){
        int n=int.Parse(System.Console.ReadLine());
        int[] x=System.Console.ReadLine().Trim().Split(' ').Select(z=>int.Parse(z)).ToArray();
        Array.Sort(x);
        System.Console.WriteLine(x[n-1]-x[0]);
    }
}