using System;
using System.Linq;
public class Hello{
    public static void Main(){
        var input = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var A = input[0];
        var K = input[1];
        if(K == 0){
            Console.WriteLine(2000000000000 - A);
            return;
        }
        var cnt = 0;
        while(A < 2000000000000){
            A += 1 + A * K;
            cnt++;
        }
        Console.WriteLine(cnt);
    }
}