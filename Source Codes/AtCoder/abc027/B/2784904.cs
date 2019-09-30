using System;
using System.Collections.Generic;
using System.Linq;
public class Hello{
    public static void Main(){
        var N = int.Parse(Console.ReadLine());
        var men = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
        if(men.Sum() % N != 0){
            Console.WriteLine(-1);
            return;
        }
        var count = 0;
        var one = men.Sum() / N;
        var sum = 0;
        for(var i = 0;i < N;i++){
            sum += men[i];
            if(sum % (i + 1) != 0 || sum != one * (i + 1)){
                count++;
            } 
        }
        Console.WriteLine(count);
    }
}