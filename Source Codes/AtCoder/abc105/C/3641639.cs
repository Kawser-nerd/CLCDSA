using System;
using System.Linq;

class p{
  static void Main(){
    int N = int.Parse(Console.ReadLine());
    string ans = "";
    while (N != 0) {
      if (N % 2 != 0) {
        ans = "1" + ans;
        N = (N - 1) / -2;
      }else{
        ans = "0" + ans;
        N /= -2;
      }
    }
    Console.WriteLine(ans == "" ? "0" : ans);
  }
}