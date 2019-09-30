using System;
public class Hello{
    public static void Main(){
        var N = int.Parse(Console.ReadLine());
        
        var Lucas = new long[87];
        Lucas[0] = 2;
        Lucas[1] = 1;
        
        for(var i = 2;i < 87;i++){
            Lucas[i] = Lucas[i - 1] + Lucas[i - 2];
        }
        
        Console.WriteLine(Lucas[N]);
    }
}