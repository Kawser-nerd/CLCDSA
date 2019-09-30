using System;
class Program{
    static void Main(){
        // Your code here!
        string[] input = Console.ReadLine().Split(' ');
        string x = input[0];
        string y = input[1];
        int xNum = StringToNumber(x);
        int yNum = StringToNumber(y);
        if(xNum > yNum){
            Console.WriteLine(">");
        }else if(xNum == yNum){
            Console.WriteLine("=");
        }else{
            Console.WriteLine("<");
        }
    }
    
    static int StringToNumber(string str){
        switch(str){
            case "A":
                return 0;
            case "B":
                return 1;
            case "C":
                return 2;
            case "D":
                return 3;
            case "E":
                return 4;
            case "F":
                return 5;
            default:
                return -1;
        }
    }
}