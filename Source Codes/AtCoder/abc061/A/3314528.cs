using System;
using static System.Console;
using static System.Math;
 
public class Hello{
    public static void Main(){
        string[] put = ReadLine().Split(' ');
      	int a = int.Parse(put[0]);
      int b = int.Parse(put[1]);
      int c = int.Parse(put[2]);
      if(a<=c && c<=b){
        WriteLine("Yes");
      }else{
        WriteLine("No");
      }
    }
}