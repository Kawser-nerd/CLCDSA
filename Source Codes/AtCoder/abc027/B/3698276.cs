using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    ?int n = int.Parse(Console.ReadLine());
    	    ?List<int> islands = new List<int>();
    	    ?string[] str = Console.ReadLine().Split(' ');
    	    ?for(int i = 0 ; i < n ; i++) islands.Add(int.Parse(str[i]));
    	      int sum = islands.Sum();
    	      int bridge = 0;
    	      
    	      
    	      if(sum % n != 0)
    	      {
    	          Console.WriteLine(-1);
    	      }
    	      else
    	      {
    	          int a = sum / n;
    	          int b = 0;
    	          int c = 0;
    	          for(int i = 1 ; i < n ; i++)
    	          {
    	              b = 0;
    	              c = 0;
    	              for(int j = 0 ; j < i ; j++)
    	              {
    	                  b += islands[j];
    	              }
    	              for(int k = i ; k < n ; k++)
    	              {
    	                  c += islands[k];
    	              }
    	              
    	              if(b != i*a || c != (n-i)*a) bridge++;
    	          }
    	          Console.WriteLine(bridge);
    	      }
    	     
    	}
    }
}