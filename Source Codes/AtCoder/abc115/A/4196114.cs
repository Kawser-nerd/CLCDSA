using System;
class Program
{
    static void Main(string[] args)
    {
        var ev = " Eve";
        var D = Console.ReadLine();
        
        var dInt = int.Parse(D);
        var result = "Christmas";
        
        for(int i=0; i<25-dInt; i++) {
            result += ev;
        }
        
        Console.WriteLine(result);
    }
}