using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _1a
{
    public class KillerWord
    {
        public class node
        {
            public Dictionary<int, node> next = new Dictionary<int,node>();
            public int count;
            public int index;
        }


        List<string> words;
        List<string> lists;
        int[,] let;

        string order;

        Dictionary<int, node> root;
        
        public KillerWord(StreamReader r)
        {
            int n, m;
            string[] x = r.ReadLine().Split(' ');
            n = int.Parse(x[0]);
            m = int.Parse(x[1]);

            words = new List<string>();
            lists = new List<string>();

            for (int i = 0; i < n; i++)
            {
                words.Add(r.ReadLine());
            }

            for (int i = 0; i < m; i++)
            {
                lists.Add(r.ReadLine());
            }
        }


        
        public void addword(int word, node n)
        {            
            n.count++;
            if (n.index == order.Length) return;

            int l = order[n.index] - 'a';
            int x = let[word, l];

            
            if (!n.next.ContainsKey(x))
            {
                n.next[x] = new node();
                n.next[x].index = n.index + 1;
            }
            addword(word, n.next[x]);                                    
        }

        public int count(int word)
        {
            int score = 0;

            for (node n = root[words[word].Length]; n.index != order.Length; )
            {
                int l = order[n.index] - 'a';
                int x = let[word, l];

                if (x != 0)
                    n = n.next[x];
                else
                {
                    if (n.next.Count > 1)
                        score++;

                    n = n.next[x];
                }


            }

            return score;
        }




        public int simcount(string word)
        {

            bool[] invalid = new bool[words.Count];

            int cnt = 0;
            foreach (char c in order)
            {
                bool valid = false;

                for(int i =0; i<words.Count; i++)
                {
                    if (word.Length != words[i].Length) continue;
                    if (words[i].Contains(c) && !invalid[i])
                    {
                        valid = true;
                        break;
                    }
                }

                if (!word.Contains(c))
                {
                    if (valid) cnt++;
                    for (int i = 0; i < words.Count; i++)
                    {
                        if (word.Length != words[i].Length) continue;
                        if (!invalid[i] && words[i].Contains(c))
                            invalid[i] = true;
                    }
                }
                else
                {
                    for (int i = 0; i < words.Count; i++)
                    {
                        if (word.Length != words[i].Length) continue;
                        if (!invalid[i] && !words[i].Contains(c))
                        {
                            invalid[i] = true;
                            continue;
                        }

                        for(int j = 0; j<word.Length; j++)
                        {
                            if ((word[j] == c || words[i][j] == c) && (word[j] != words[i][j]))
                            {
                                invalid[i] = true;
                                break;
                            }
                        }


                    }
                }
            }

            return cnt;
        }

        public string solve()
        {
            let = new int[words.Count, 'z' - 'a'+1];

            for (int i = 0; i < words.Count; i++)
            {
                for (int j = 'a'; j <= 'z'; j++)
                {
                    let[i, j - 'a'] = 0;
                    for (int k = 0; k < words[i].Length; k++)
                        if (words[i][k] == j)
                            let[i, j - 'a'] |= 1 << k;                    
                }
            }

            string ret = "";

            foreach (string s in lists)
            {
                order = s;
                root = new Dictionary<int,node>();

                for (int i = 0; i < words.Count; i++)
                {
                    if (!root.ContainsKey(words[i].Length))
                        root[words[i].Length] = new node();
                    addword(i, root[words[i].Length]);
                }

                int best = -1;
                string bests = "";

                for (int i = 0; i < words.Count; i++)
                {
                    int l = count(i);
/*                    int ll = simcount(words[i]);
                    if (l != ll)
                    {
                        Console.WriteLine("?");
                    }
                    */
                    if (l > best)
                    {
                        best = l;
                        bests = words[i];
                    }
                }

                if (ret != "")
                    ret += " ";
                ret += bests;
                Console.WriteLine(bests);

            }

            return ret;
        }

    }
}
