using System;
class M {
  static void Main(string[] _) {
    var A = int.Parse( Console.ReadLine() );
    var B = int.Parse( Console.ReadLine() );
    var C = int.Parse( Console.ReadLine() );
    var X = int.Parse( Console.ReadLine() );
    
    int cnt = 0;
    for(int a=0;a<=A;++a){
      for(int b=0;b<=B;++b){
        for(int c=0;c<=C;++c){
          int val = a * 500 + b * 100 + c * 50;
          if ( val == X ) cnt ++;            
        }
      }
    }
    Console.Write(cnt);
    
  }
}