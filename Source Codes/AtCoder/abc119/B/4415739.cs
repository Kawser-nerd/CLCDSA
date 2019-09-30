using System;
using System.Linq;

class ABC119B{
    public static void Main(){
        var N = int.Parse(Console.ReadLine());
        var Sum = 0.0;
        var input = new String[]{};
        foreach(var n in Enumerable.Range(0,N)){
            input = Console.ReadLine().Split();
            switch(input[1]){
                case "BTC":
                    Sum += double.Parse(input[0])*380000;
                    continue;
                case "JPY":
                    Sum += double.Parse(input[0]);
                    continue;
            }
        }
        Console.WriteLine(Sum);
    }
}