using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{   
        string s1 = Console.ReadLine();
        string s2 = Console.ReadLine();
        char[] c = new char[8] { 'a', 't', 'c', 'o', 'd' ,'e' ,'r' , '@'};
        bool win = true;
        for(int i = 0 ; i < s1.Length ; i++)
        {
            if(s1[i]!=s2[i] && s1[i] != '@' && s2[i] != '@') win = false;
            if(s1[i]=='@')
            {
                if(!c.Contains(s2[i])) win = false;
            }
            if(s2[i]=='@')
            {
                if(!c.Contains(s1[i])) win = false;
            }
        } 
        
        if(win) Console.WriteLine("You can win");
        else Console.WriteLine("You will lose");
	}
}