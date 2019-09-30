using System;
public class Hello{
    public static void Main(){
        var n = long.Parse(Console.ReadLine());
        bool isPrime = false;
        if(n == 1){
            isPrime = false;
        }else if(n == 2 || n == 3 || n == 5){
            isPrime = true;
        }else if(n % 2 != 0 && n % 3 != 0 && n % 5 != 0){
            isPrime = true;
        }
        if(isPrime){
            Console.WriteLine("Prime");
        }else{
            Console.WriteLine("Not Prime");
        }
    }
}