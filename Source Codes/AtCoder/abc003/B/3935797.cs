using System;
using System.Collections.Generic;
using System.Linq;

namespace B {
    class Program {
        static void Main (string[] args) {
            var s = Console.ReadLine ();
            var t = Console.ReadLine ();

            // calc
            var atcorder = "atcoder";
            var notContainSameCharSTindex = Enumerable.Range (0, s.Count ()).Where (i => s[i] != t[i]);
            var output = "";
            if (!notContainSameCharSTindex.Any ()) {
                output = "You can win";
            } else {

                var sIsSameT = notContainSameCharSTindex.All (i => {
                    var at = ' ';
                    if (s[i] == '@') {
                        at = t[i];
                    } else if (t[i] == '@') {
                        at = s[i];
                    } else {
                        return false;
                    }
                    return atcorder.Contains (at);
                });
                if (sIsSameT) {
                    output = "You can win";
                } else {
                    output = "You will lose";
                }
            }

            Console.WriteLine (output);
        }
    }
}