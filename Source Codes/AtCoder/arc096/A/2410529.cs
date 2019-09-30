using System;

class Program{
  static void Main(string[] args){
    var array = Console.ReadLine().Split(' ');
    var A = int.Parse(array[0]);
    var B = int.Parse(array[1]);
    var C = int.Parse(array[2]);
    var X = int.Parse(array[3]);
    var Y = int.Parse(array[4]);
    var sum = 0;
    if(X>Y){
      if(A+B > 2*C){
        sum += 2 * C * Y;
      }
      else{
        sum += (A + B) * Y;
      }
      if(A > 2 * C){
        sum += 2*C*(X-Y);
      }
      else{
        sum += A * (X-Y);
      }
    }
    else{
      if(A+B > 2*C){
        sum += 2 * C * X;
      }
      else{
        sum += (A + B) * X;
      }
      if(B > 2 * C){
        sum += 2*C*(Y-X);
      }
      else{
        sum += B * (Y-X);
      }
    }
    Console.WriteLine(sum);
  }
}