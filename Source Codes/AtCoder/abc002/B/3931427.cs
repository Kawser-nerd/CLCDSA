using System;
using System.Linq;

namespace B {
    class Program {
        static void Main (string[] args) {
            var chokudai = Console.ReadLine ();
            var vowels = "aiueo";

            foreach (var vowel in vowels) {
                chokudai = string.Concat (chokudai.Where ((c) => c != vowel));
            }
            Console.WriteLine (chokudai);
        }
    }
}