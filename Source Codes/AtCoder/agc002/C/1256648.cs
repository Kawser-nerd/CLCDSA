using System;
    using System.Linq;
    using System.Collections.Generic;
    using System.Text.RegularExpressions;
    using System.Text;
     
    public class Program
    {
        public void Proc() {
            Reader.IsDebug = false;
            long[] inpt = Reader.ReadLine().Split(' ').Select(a=>long.Parse(a)).ToArray();

            int itemCount = (int)inpt[0];
            long minLength = inpt[1];

            long[] list = Reader.ReadLine().Split(' ').Select(a=>long.Parse(a)).ToArray();

            for(int i=1; i<list.Length; i++) {
                if(list[i-1]+list[i]>=minLength) {
                    Console.WriteLine("Possible");
                    StringBuilder ans = new StringBuilder();
                    for(int j=0; j<i-1; j++) {
                        ans.AppendLine((j+1).ToString());
                    }
                    for(int j=list.Length-2; j>=i; j--) {
                        ans.AppendLine((j+1).ToString());
                    }
                    ans.AppendLine(i.ToString());
                    Console.Write(ans.ToString());
                    return;
                }
            }
            Console.WriteLine("Impossible");
        }



        public class Reader {
            public static bool IsDebug = true;
            private static System.IO.StringReader SReader;
            private static string InitText = @"




2 21
10 10





";
            public static string ReadLine() {
                if(IsDebug) {
                    if(SReader == null) {
                        SReader = new System.IO.StringReader(InitText.Trim());
                    }
                    return SReader.ReadLine();
                } else {
                    return Console.ReadLine();
                }
            }
        }
        public static void Main(string[] args)
        {
            Program prg = new Program();
            prg.Proc();
        }
    }