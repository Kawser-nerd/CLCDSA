using System;

class pro{

  static void Main(){
    
    int input = int.Parse(Console.ReadLine());
    int ans = 1;
    for(int b = 2; b * b <= input; b++){
      for(int p = 2;; p++){
        int t = (int)Math.Pow(b,p);
        if(t <= input) ans = Math.Max(ans,t);
        else break;
      }
    }
    Console.WriteLine(ans);
  }
}