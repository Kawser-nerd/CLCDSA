using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProgrammingContestPractice
{
    class Alien_Language
    {
        static void Main(string[] args){

            string strInputFile = "C:\\GoogleCodeJamInputOutput\\Alien_Language\\A-small-attempt0.in";
            //string strInputFile = "C:\\GoogleCodeJamInputOutput\\Alien_Language\\B-large-practice.in";
            //string strInputFile = "C:\\GoogleCodeJamInputOutput\\Alien_Language\\sample.in.txt";
            //string strInputFile = "C:\\GoogleCodeJamInputOutput\\Alien_Language\\Copy of sample.in.txt";
            
            System.IO.TextReader tr = new StreamReader(strInputFile);
            System.IO.TextWriter tw = new StreamWriter(strInputFile + ".out.txt");

            String[] strLine = tr.ReadLine().Split(' ');
            int L = Int32.Parse(strLine[0]);
            int D = Int32.Parse(strLine[1]);
            int iTotalTestCases = Int32.Parse(strLine[2]);

            HashSet<string> dict = new HashSet<string>();
            for (int iWord = 0; iWord < D; iWord++)
            {
                Add(dict, tr.ReadLine());                
            }

            for (int iCase = 0; iCase < iTotalTestCases; iCase++)
            {
                string patt = tr.ReadLine();
                tw.WriteLine("Case #{0}: {1}", (1 + iCase), Count(patt, dict));
            }

            tr.Close();
            tw.Close();

            Console.WriteLine("press any key to continue");
            Console.ReadKey();            
        }
        static void test(){
            HashSet<string > dict = new HashSet<string>();
            Add(dict, "abc");
            Add(dict, "bca");
            Add(dict, "dac");
            Add(dict, "dbc");
            Add(dict, "cba");
            Console.WriteLine("#" + Count("(ab)(bc)(ca)", dict));
            Console.WriteLine("#" + Count("abc", dict));
            Console.WriteLine("#" + Count("(abc)(abc)(abc)", dict));
            Console.WriteLine("#" + Count("(zyx)bc", dict));
            Console.ReadLine();
        }

        static long iCount = 0;
        static StringBuilder wordofar = new StringBuilder();

        static void Add(HashSet<string> dict, string word){
            StringBuilder sb = new StringBuilder();
            foreach(char ch in word){
                sb.Append(ch);
                dict.Add(sb.ToString());
            }
        } 
        static string[] getTokens(string patt){
            LinkedList<string> lst = new LinkedList<string>();
            string currtkn = "";
            bool insideparen = false;
            foreach (char ch in patt)
            {
                if (ch == ')')
                {
                    if (currtkn.Length > 0) lst.AddLast(currtkn);
                    insideparen = false;
                    currtkn = "";
                }
                else if (ch == '(')
                {
                    insideparen = true;
                }
                else
                {
                    if (insideparen)
                    {
                        currtkn += "" + ch;
                    }
                    else
                    {
                        lst.AddLast("" + ch);
                        currtkn = "";
                    }
                }
            }
            if (currtkn.Length > 0) lst.AddLast(currtkn);

            return lst.ToArray<string>();
        }
        static long Count(string patt, HashSet<string> dict){
            string[] tokens = getTokens(patt);
            iCount = 0;
            wordofar = new StringBuilder();
            Count(0, tokens, dict);
            return iCount;
        }

        private static void Count(int it, string[] tokens, HashSet<string> dict)
        {
            if (it == tokens.Length) {
                iCount++;
            }
            else
            {
                for (int i = 0; i < tokens[it].Length; i++)
                {
                    wordofar.Append(tokens[it][i]);
                    if (dict.Contains(wordofar.ToString()))
                    {
                        Count(it + 1, tokens, dict);
                    }
                    wordofar.Remove(wordofar.Length - 1, 1);
                }
            }
        }
    }
}
