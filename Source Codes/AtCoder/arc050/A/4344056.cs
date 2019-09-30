using System;
public class Hello{
    public static void Main(){
        var line = Console.ReadLine().Split(' ');
        if(line[0] == line[1].ToUpper()){
            Console.WriteLine("Yes");
        }else{
            Console.WriteLine("No");
        }
    }
}