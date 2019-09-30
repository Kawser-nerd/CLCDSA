using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.IO;
using Microsoft.Scripting.Math;

namespace myNameSpace
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            //Application.EnableVisualStyles();
            //Application.SetCompatibleTextRenderingDefault(false);
            //Application.Run(new Form1());
            start();

        }
        public static void start()
        {
            string nameFileInput = "C:\\Users\\Administrator\\Desktop\\input\\input.txt";
            string nameFileOutput = "C:\\Users\\Administrator\\Desktop\\input\\output.txt";
            StreamReader StreamReaderFile = new StreamReader(nameFileInput);
            StreamWriter StreamWriterFile = new StreamWriter(nameFileOutput);

           

            string[] inpupFistLine = StreamReaderFile.ReadLine().Split(' ');
            int numberOfCase = Int32.Parse(inpupFistLine[0]);


            for (int i = 0; i < numberOfCase; i++)
            {
                inpupFistLine = StreamReaderFile.ReadLine().Split(' ');
                ulong A1 = (ulong)Int32.Parse(inpupFistLine[0]);
                ulong A2 = (ulong)Int32.Parse(inpupFistLine[1]);
                ulong B1 = (ulong)Int32.Parse(inpupFistLine[2]);
                ulong B2 = (ulong)Int32.Parse(inpupFistLine[3]);

                int count = oneCaseProcess(A1,A2,B1,B2);

                StreamWriterFile.WriteLine("Case #" + (i + 1) + ": " + count);
            }
            StreamWriterFile.Close();            
        }

        public static int oneCaseProcess(ulong A1, ulong A2, ulong B1, ulong B2)
        {
            int count = 0;
            for (ulong i = A1; i <= A2; i++)
            {
                for (ulong j = B1; j <= B2; j++)
                {
                    ulong A;
                    ulong B;
                    if (i <= j)
                    {
                        A = i;
                        B = j;
                    }
                    else
                    {
                        A = j;
                        B = i;
                    }
                    if (true == su1(A, B))
                    {
                        count++;
                    }

                }
            }
            return count;
        }

        public static bool su1(ulong A, ulong B)
        {
            //A 1 3   B win
            //B 2 4   A win
            int cout = 0;
            ulong k;
            while (true)
            {
                cout++;
                if (A == B)
                {
                    break;
                }

                k = findk(A, B);

                if (k > 1)
                {
                    cout++;
                    break;
                }


                B = B - (k * A);

                ulong backA = A;
                A = B;
                B = backA;
                // MessageBox.Show("count = "+cout+"  "+A+" : " + B);
            }
            //MessageBox.Show("count = "+cout);
            if (cout % 2 == 0)
                return true;
            else

                return false;
        }
        public static ulong findk(ulong A, ulong B) //b>=A
        {
            ulong k;
            if (A == B)
            {
                k = 1;
            }
            else if (B % A == 0)
            {
                k = (B / A) - 1;
            }
            else
            {
                k = B / A;
            }
            return k;
        }


    }
}
