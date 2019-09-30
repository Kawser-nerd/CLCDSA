using System;

class A{
    static void Main(){
        var a = int.Parse(Console.ReadLine());
        var b = int.Parse(Console.ReadLine());

        var need = a % b;
        if(need == 0){
            Console.WriteLine(0);
        }
        else{
            Console.WriteLine(b - need);
        }
    }
}