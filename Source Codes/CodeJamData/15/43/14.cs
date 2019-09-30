using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace test
{
    class Program
    {
        static int ans=999999999;
        static List<string[]> words;
        static HashSet<string> eng_words;
        static HashSet<string> fr_words;
        
        static void Main(string[] args)
        {
            int tt= int.Parse(Console.ReadLine());
            StreamWriter s=new StreamWriter(File.Open("o.out",FileMode.Create));
            for(int cc=1; cc <= tt; cc++)
            {
                int n= int.Parse(Console.ReadLine());
                ans = 999999999;

                eng_words = new HashSet<string>(
                    Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
                fr_words = new HashSet<string>(
                    Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
                words = new List<string[]>();

                for(int i=2; i < n; i++)
                {
                    words.Add(Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
                }

                for(int ct=0; ct < (1 << (n - 2)); ct++)
                {
                    HashSet<string> n_eng_words=new HashSet<string>(eng_words);
                    HashSet<string> n_fr_words=new HashSet<string>(fr_words);
                    for(int i=0;i+2<n;i++)
                        if((ct & (1 << i)) != 0)
                        {
                            foreach(var w in words[i])
                                if(!n_eng_words.Contains(w))
                                    n_eng_words.Add(w);
                        }
                        else
                        {
                            foreach(var w in words[i])
                                if(!n_fr_words.Contains(w))
                                    n_fr_words.Add(w);
                        }
                    int tans=0;
                    foreach(var w in n_eng_words)
                        if(n_fr_words.Contains(w))
                            tans++;
                    ans = Math.Min(ans, tans);
                }

                Console.WriteLine("Case #" + cc.ToString() + ": " + ans.ToString());
                s.WriteLine("Case #" + cc.ToString() + ": " + ans.ToString());
            }
            s.Close();
        }
    }
}
