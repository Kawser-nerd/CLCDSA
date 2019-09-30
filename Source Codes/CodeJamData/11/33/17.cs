using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace taskC {
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
                        sw.WriteLine(String.Format("Case #{0}: {1}", i + 1, SolveTaskC(sr)));
                    }
                }
            }
        }
        private static string SolveTaskC(StreamReader sr) {
            StringBuffer buffer = new StringBuffer(sr.ReadLine());
            int N = buffer.ReadInt();
            int L = buffer.ReadInt();
            int H = buffer.ReadInt();
            buffer = new StringBuffer(sr.ReadLine());
            int[] f = new int[N];
            for (int i = 0; i < N; i++)
                f[i] = buffer.ReadInt();
            Array.Sort(f);
            for (int i = L; i <= H; i++) {
                if (IsCorrectF(f, i))
                    return i.ToString();
            }
            return "NO";
        }
        static bool IsCorrectF(int[] f, int fr) {
            for(int i = 0; i < f.Length; i++) {
                int n = f[i];
                if (f[i] % fr == 0 || fr % f[i] == 0)
                    continue;
                return false;
            }
            return true;


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
        public int ReadInt() {
            string value = parts[currentIndex];
            currentIndex++;
            return Int32.Parse(value);
        }
        public string ReadString() {
            string value = parts[currentIndex];
            currentIndex++;
            return value;
        }
    }
}
