using System;
using System.Linq;
using System.Collections.Generic;

namespace ABC039_C{
    class Program {
        static void Main(string[] args){
            var s = Console.ReadLine();
            var note = new string[]{"Do","","Re","","Mi","Fa","","So","","La","","Si"};
            var piano = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
            Console.WriteLine(note[piano.IndexOf(s)]);
        }
    }
}