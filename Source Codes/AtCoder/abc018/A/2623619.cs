using System;
public class Hello{
    public static void Main(){
        int A = int.Parse(Console.ReadLine());
        int B = int.Parse(Console.ReadLine());
        int C = int.Parse(Console.ReadLine());
        
        if(A > B && A > C){
            Console.WriteLine(1);
            if(B > C){
                Console.WriteLine("2" + "\n" + "3");
            }else{
                Console.WriteLine("3" + "\n" + "2");
            }
        }else if(B > A && B > C){
            if(A > C){
                Console.WriteLine("2" + "\n" + "1" + "\n" + "3");
            }else{
                Console.WriteLine("3" + "\n" + "1" + "\n" + "2");
            }
        }else{
            if(A > B){
                Console.WriteLine("2" + "\n" + "3" + "\n" + "1");
            }else{
                Console.WriteLine("3" + "\n" + "2" + "\n" + "1");
            }
        }
    }
}