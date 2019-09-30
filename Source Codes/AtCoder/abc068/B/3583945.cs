using System;
using System.Linq;

class prog{
  static void Main(){
    int N = int.Parse(Console.ReadLine());
    int ans = 0;
    for(int i = 0; ; i++){
      if(Math.Pow(2, i) <= N) ans = (int)Math.Pow(2, i);
      if(Math.Pow(2, i) > N) break;
    }
    Console.WriteLine(ans);
      
  }
}