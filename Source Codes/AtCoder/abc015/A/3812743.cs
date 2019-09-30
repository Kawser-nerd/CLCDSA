using System;

class A{
    static void Main(){
        var a = Console.ReadLine();
        var b = Console.ReadLine();

        if(a.Length > b.Length){
            Console.WriteLine(a);
        }
        else{
            Console.WriteLine(b);
        }
    }
}