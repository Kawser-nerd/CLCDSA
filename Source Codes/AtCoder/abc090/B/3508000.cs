using System;
using System.Linq;
 
class Program {
   static void Main(){
     
     string[] input = Console.ReadLine().Split().ToArray();
     int A = int.Parse(input[0]);
     int B = int.Parse(input[1]);
     
     int count = 0;
     for(int i = A; i <= B; i++){
       string I = i.ToString();
       if(I[0] == I[4]&&I[1] == I[3]) count++;
     }
     
     Console.WriteLine(count);
     
   }
}