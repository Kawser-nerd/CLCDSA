using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;
using System.IO;

namespace ProbB
{
    class ProbB
    {
        static void Main(string[] args)
        {

            //string inFile = "Test.txt";
            //string outFile = "out.txt";

            string inFile = "B-small-attempt0.in";
            string outFile = "B-small0.out";

            //string inFile = "B-large.in"
            //string outFile = "B-large.out"


            FileStream aFile = new FileStream(inFile, FileMode.Open);
            StreamReader SR = new StreamReader(aFile);

            FileStream bFile = new FileStream(outFile, FileMode.Create);
            StreamWriter SW = new StreamWriter(bFile);





            int N;
            string input;

            input = SR.ReadLine();
            N = int.Parse(input);


            for (int i = 0; i < N; i++)
            {
                input = SR.ReadLine();
                string[] line = input.Split(' ');




                count = 0;

                par(line[0], 0, 1, 1);






                StringBuilder sb = new StringBuilder();

                sb.AppendFormat("Case #{0}: ", i + 1);
                sb.Append(count);



                string outText = sb.ToString();

                //output two copies of the output, one to Terminal, and one to a file.
                Console.WriteLine(outText);
                SW.WriteLine(outText);

            }



            SR.Close();
            SW.Close();

            // get console to hang at the end.
            Console.ReadLine();


        }

        public static int count;

        public static void par(String s, Int64 num, Int64 sign, int len)
        {


            if( (s.Length == len)) {

                num = num + sign * Int64.Parse(s.Substring(0, len));

                if( (num%2 == 0) || (num%3 == 0) || (num%5 == 0) || (num%7 == 0) )
                {
                count ++;
                }
                return;
            }




            Int64 numTemp = num + sign * Int64.Parse(s.Substring(0, len));
            
            
            par(s.Substring(len), numTemp, +1, 1);


            par(s.Substring(len), numTemp, -1, 1);

            
            par(s, num, sign, len+1);







        }

    }
}
