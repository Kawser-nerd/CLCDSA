using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    string[] s = Console.ReadLine().Split(' ');
	    string s1 = s[0];
	    string s2 = s[1];
	    string s3 = s[2];
	    string ans = (s1[0] +""+ s2[0] +""+ s3[0]).ToString();
	    
	    Console.WriteLine(ans.ToUpper());
	    
	    
	} 
}