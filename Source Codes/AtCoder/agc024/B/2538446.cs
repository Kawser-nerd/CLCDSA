using System;
using System.Collections.Generic;

namespace Backfront {
    class ConsoleInput {
        private string[] currentLine = null;
        private int currentCursor = 0;

        public string Get() {
            if (currentLine == null || currentCursor >= currentLine.Length) {
                currentLine = Console.ReadLine().Split(' ');
                currentCursor = 0;
            }
            var res = currentLine[currentCursor];
            currentCursor++;
            return res;
        }

        public int GetInt() {
            return int.Parse(Get());
        }
    }
    
    struct Pair : IComparable<Pair>{
        public int index;
        public int value;

        public int CompareTo(Pair other) {
            return this.value - other.value;
        }
    }

    class Program {
        static ConsoleInput input = new ConsoleInput();

        static void Main(string[] args) {
            int N = input.GetInt();
            var P = new List<Pair>();
            for(int i = 0; i < N; ++i) {
                P.Add(new Pair {
                    index = i,
                    value = input.GetInt()
                });
            }

            P.Sort();

            int counter = 1;
            int maxCount = 1;
            for(int i = 0; i < N - 1; ++i) {
                if(P[i].index < P[i + 1].index) {
                    counter++;
                    if (counter > maxCount) maxCount = counter;
                }
                else {
                    counter = 1;
                }
            }
            Console.WriteLine(N - maxCount);
        }
    }
}