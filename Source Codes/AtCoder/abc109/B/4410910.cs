using System;
using System.Collections.Generic;
class Program
{
    //static List<string> str = new List<string>();
    static void Main(string[] args)
    {
        // ??
        //string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(Console.ReadLine());

        // ???????
        List<string> shiritori = new List<string>();
        bool ret = true;
        string post = ""; // ??????
        for (int i = 0; i < N; i++)
        {
            string word = Console.ReadLine();
            if (!ret) continue;

            // ??????1???
            if(shiritori.Contains(word))
            {
                ret = false;
            }
            else
            {
                shiritori.Add(word);
            }

            if(post != "" && post[post.Length - 1].CompareTo(word[0]) != 0)
            {
                ret = false;
            }
            post = word;

        }

        //Console.WriteLine(ret);
        if (ret)
            Console.WriteLine("Yes");
        else
            Console.WriteLine("No");
    }

}