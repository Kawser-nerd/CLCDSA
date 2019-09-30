using System;
public class Hello{
    static long Count(long n,long x){
        if(n < 0){
            return 0;
        }else{
            return n / x + 1;
        }
    }
    public static void Main(){
        var array = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
        var a = array[0];
        var b = array[1];
        var x = array[2];
        var count = (Count(b,x) - Count(a - 1,x));
        
        
        Console.WriteLine(count);
    }
}