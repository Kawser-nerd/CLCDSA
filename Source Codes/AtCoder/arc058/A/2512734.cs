using System;
using System.Collections.Generic;
using System.Linq;

class Program{


  static int k, cost;
  static bool yn = false;

  static int Main() {

    string[] nyu = new string[2];
    nyu = Console.ReadLine().Split(' ');

    char[] n = nyu[0].ToCharArray();
    cost = int.Parse(nyu[0]);
    k = int.Parse(nyu[1]);

    char[] d = new char[k];
    string[] nya = new string[k];
    nya = Console.ReadLine().Split(' ');

    for (int i = 0; i < k ; i ++){
      d[i] = nya[i][0];
    }

    while (true) {
      yn = false;

      for (int i = 0; i < n.Length; i++) {
        for ( int j = 0; j < d.Length; j ++) {
          if (n[i] == d[j]) {
            yn = true;
            break;
          }
        }
        if (yn == true) break;
      }

      if ( yn == true) {
        cost ++;
        string str = cost.ToString();
        n = str.ToCharArray();
      }else {
        break;
      }
    }



    Console.WriteLine("{0}", cost);

    return 0;
  }

}