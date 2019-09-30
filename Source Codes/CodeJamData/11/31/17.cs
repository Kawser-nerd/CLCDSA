using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace taskA {
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
                        sw.Write(String.Format("Case #{0}:\n{1}", i + 1, SolveTaskA(sr)));
                    }
                }
            }
        }
        private static string SolveTaskA(StreamReader sr) {
            string input = sr.ReadLine();
            StringBuffer buffer = new StringBuffer(input);
            int r = buffer.ReadInt();
            int c = buffer.ReadInt();            
            string[] str = new string[r];
            for (int i = 0; i < r; i++)
                str[i] = sr.ReadLine();            
            
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (str[i][j] != '#')
                        continue;
                    if(IsBlue(str, i , j) && IsBlue(str, i + 1 , j) &&IsBlue(str, i , j+1) &&IsBlue(str, i+1 , j+1)) {
                        str[i] = str[i].Remove(j, 2).Insert(j, @"/\");
                        str[i + 1] = str[i+1].Remove(j, 2).Insert(j, @"\/");                        
                    }
                }
            }
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < r; i++) {
                if (str[i].Contains("#"))
                    return "Impossible\n";
                result.AppendLine(str[i]);                
            }
            return result.ToString();
        }

        private static bool IsBlue(string[] str, int r, int c) {
            if (r < 0 || r >= str.Length)
                return false;
            if (c < 0 || c >= str[r].Length)
                return false;
            return str[r][c] == '#';
            
        }

        private static int CalculateLastMoveTime(int currentPosition, int targetButtonIndex, int lastMoveTime, int otherRobotLastMoveTime) {
            int minTime = Math.Abs(currentPosition - targetButtonIndex) + 1;
            return Math.Max(minTime + lastMoveTime, otherRobotLastMoveTime + 1);

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
