using System;
using System.Collections;
using System.Collections.Generic;

namespace ABC008 {
  class ProblemB {
    static void Main(string[] args) {
      var n = int.Parse(System.Console.ReadLine());
      var s = new string[n];
      for (int i = 0; i < n; i++) {
        s[i] = System.Console.ReadLine();
      }
      
      Dictionary<string, int> person = new Dictionary<string, int>();
      var max = 0;
      var ans = "";
      for (int i = 0; i < n; i++) {
        if (person.ContainsKey(s[i])) {
          person[s[i]]++;
        } else {
          person.Add(s[i], 1);
        }
      }
      foreach (var kv in person) {

        if (kv.Value > max) {
          max = kv.Value;
          ans = kv.Key;
        }
      } 
      System.Console.WriteLine(ans);
    }

  }
}