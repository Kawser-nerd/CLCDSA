using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace taskB {
    class Program {
        static void Main(string[] args) {
            if (args.Length != 1) {
                Console.WriteLine("specify input file");
            }
            string path = args[0];
            using (StreamWriter sw = new StreamWriter(path + ".out")) {
                using (StreamReader sr = new StreamReader(path)) {
                    int count = Int32.Parse(sr.ReadLine());
                    for (int i = 0; i < count; i++) {
                        sw.WriteLine(String.Format("Case #{0}: {1}", i + 1, SolveTaskB(sr)));
                    }
                }
            }
        }

        private static Int64 SolveTaskB(StreamReader sr) {
            string input = sr.ReadLine();
            StringBuffer buffer = new StringBuffer(input);
            Int64 L = buffer.ReadInt();
            Int64 t = buffer.ReadInt();
            Int64 N = buffer.ReadInt();
            Int64 C = buffer.ReadInt();
            Int64[] a = new Int64[C];
            Int64[] d = new Int64[N];//d[i] - distance from i to i+1
            for (int i = 0; i < C; i++)
                a[i] = buffer.ReadInt();
            for(int i = 0; i < N; i++) {
                d[i] = a[i % C];
            }

            Int64 totalTime = 0;
            Int64 index = 0;            
            while(index < N && totalTime + d[index] * 2 < t) {
                totalTime += d[index] *2;//2 hours per parsec;
                index++;
            }
            if (index == N )
                return totalTime;
            Int64 restCount = N - index;
            Int64 rem = 0;
            if (totalTime + d[index] * 2 == t) {
                restCount--;
                totalTime += d[index] * 2;
                index++;
            }
            else {                
                rem = (d[index] * 2 - (t - totalTime)) / 2;
                index++;    
                totalTime=t;//TODO
            }
            if (restCount == 0)
                return totalTime;
            if (restCount == 0)
                return totalTime;
            Int64[] resultArray = new Int64[restCount];
            Array.Copy(d, index, resultArray, 0, rem > 0 ? restCount - 1 : restCount);
            if (rem > 0)
                resultArray[restCount - 1] = rem;
            Array.Sort(resultArray);
            Array.Reverse(resultArray);
            for(int i = 0; i < resultArray.Length; i++) {
                if (i < L)
                    totalTime += resultArray[i];
                else
                    totalTime += resultArray[i] * 2;
            }
            return totalTime;
        }
    }
    public class StringBuffer {
        string str;
        string[] parts;
        int currentIndex = 0;
        public StringBuffer(string str) {
            this.str = str;
            parts = str.Split(' ');
        }
        public Int64 ReadInt() {
            string value = parts[currentIndex];
            currentIndex++;
            return Int64.Parse(value);
        }
        public string ReadString() {
            string value = parts[currentIndex];
            currentIndex++;
            return value;
        }
    }
}
