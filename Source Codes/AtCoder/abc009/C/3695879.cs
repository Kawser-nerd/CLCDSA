using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static List<char> origin = new List<char>();
    public static List<char> sorted = new List<char>();
    public static string s;
    public static int n;
    public static int m;
    public static void Main()
	{
        string[] str = Console.ReadLine().Split(' ');
        n = int.Parse(str[0]);
        m = int.Parse(str[1]) ;
    
        s = Console.ReadLine();
        for(int i = 0 ; i < n ; i++)
        {
            origin.Add(s[i]);
            sorted.Add(s[i]);
        }
        sorted.Sort();
        
        string ans = "";
        
        for(int i = 0 ; i < origin.Count; i++)
        {
            for(int j = 0 ; j < sorted.Count; j++)
            {
                if(origin[i] == sorted[j] || i == n-1)
                {
                    ans += sorted[j];
                    sorted.RemoveAt(j);
                    break;
                }
                else
                {
                    char c = sorted[j];
                    sorted.RemoveAt(j);
                    int cnt = 0;
                    List<char> rList = new List<char>();
                    for(int i2 = i+1 ; i2 < origin.Count ; i2++) rList.Add(origin[i2]);
                    for(int i3 = 0 ; i3 < sorted.Count; i3++)
                    {
                        rList.Remove(sorted[i3]);
                    }
                    string ts = "";
                    for(int i4 = 0 ; i4 < rList.Count ; i4++) ts += rList[i4];
                    
                    if(rList.Count <= m-1)
                    {
                        ans += c;
                        m--;
                        break;
                    }
                    else
                    {
                        sorted.Insert(j, c);
                    }
                    
                }
            }
        }
        
        Console.WriteLine(ans);
    }
}