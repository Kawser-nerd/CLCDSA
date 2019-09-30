using System;
class A{
  static void Main(){
    Func<int> f = () => int.Parse(Console.ReadLine());
    var s = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
    var count = 0;
    var w = 0;
    for(int i = 0;i < s[0];i++){
      w+=f();
      if(s[2]>=w && w>=s[1])
        count++;
    }
    Console.WriteLine(count);
  }
}