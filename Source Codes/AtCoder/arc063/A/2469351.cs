using System;
using System.Collections.Generic;
using System.Linq;

class Program{


  static int Main() {

    int a = 0;
    string nyu = Console.ReadLine();

    for(int i = 0; i < nyu.Length-1; i++){
      if (nyu[i] != nyu[i+1]) a ++;
    }

    Console.WriteLine("{0}", a);

    return 0;
  }

}