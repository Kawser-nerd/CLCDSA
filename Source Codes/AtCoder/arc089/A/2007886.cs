using System;
    using System.Linq;
    using System.Collections.Generic;
    using System.Text.RegularExpressions;
    using System.Text;
    using System.Net;

     
    public class Program
    {

        public void Proc() {
            int pointCount = int.Parse(Reader.ReadLine());

            int posX = 0;
            int posY = 0;
            int tm = 0;
            for(int i=0; i<pointCount;i++) {
                int[] inpt = Reader.ReadLine().Split(' ').Select(a=>int.Parse(a)).ToArray();
                int diff = inpt[0]-tm;
                int mnh = Math.Abs(posX-inpt[1])+Math.Abs(posY-inpt[2]);
                if(diff<mnh) {
                    Console.WriteLine("No");
                    return;
                }
                if((diff-mnh)%2!=0) {
                    Console.WriteLine("No");
                    return;
                }
                posX = inpt[1];
                posY = inpt[2];
                tm = inpt[0];
            }
            Console.WriteLine("Yes");

        }



        public class Reader {
            public static bool IsDebug = false;
            private static System.IO.StringReader SReader;
            private static string InitText = @"



2
3 1 2
6 1 1





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
            #if DEBUG
            Reader.IsDebug = true;
            #endif
            Program prg = new Program();
            prg.Proc();
        }
    }