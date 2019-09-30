using System;
using System.Linq;
public class Hello{
    public static void Main(){
        var s = Console.ReadLine();
        if(
            (s.Contains('N') && !(s.Contains('S'))) ||
            (s.Contains('S') && !(s.Contains('N'))) ||
            (s.Contains('E') && !(s.Contains('W'))) ||
            (s.Contains('W') && !(s.Contains('E')))
            ){
                Console.WriteLine("No");
            }else{
                Console.WriteLine("Yes");
            }
    }
}