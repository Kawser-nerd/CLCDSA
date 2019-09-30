using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        string str = Console.ReadLine();
        string T = Console.ReadLine();

        bool isFind = false;
        char[] c1 = str.ToCharArray();
        char[] c2 = T.ToCharArray(); 

         List<string> list = new List<string>();
        string s;
        for(int i = 0 ; i < c1.Length - c2.Length +1 ; i++)
        {
            isFind = true;
            s = "";
            c1 = str.ToCharArray();
            for(int j = 0 ; j < c2.Length ; j++)
            {
                //Console.Write("c1 = " + c1[i+j] + "  c2 =" + c2[j] + "  j="+j );
                if(c1[i + j] == c2[j] || c1[i+j] == '?'){
                    //Console.Write("   ok ");
                }   else{
                    isFind = false;
                } 
                //Console.WriteLine();
            }
        
            if(isFind)
            {
                for(int k = 0 ; k < c2.Length ; k++){
                    c1[i+k] = c2[k];
                }
                for(int x = 0 ; x < c1.Length ; x++)
                {
                    if(c1[x] == '?') s += "a";
                    else s += c1[x].ToString();
                }
                list.Add(s);
                //Console.WriteLine(list[list.Count()-1]);
            }
        }       
        list.Sort();
        if(list.Count() > 0)
        {
            Console.WriteLine(list[0]);
        }
        else Console.WriteLine("UNRESTORABLE");
    }
}