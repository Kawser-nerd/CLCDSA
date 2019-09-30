using System;
using System.Linq;
public class Hello{
    static long XOR(long n){
        switch(n % 4){
            case 0:
            return n;
            break;
            case 1:
            return 1;
            break;
            case 2:
            return n + 1;
            break;
            default:
            return 0;
            break;
        }
    }
    public static void Main(){
        var line = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var A = line[0];
        var B = line[1];
        
        Console.WriteLine(XOR(A - 1) ^ XOR(B));
        
    }
}