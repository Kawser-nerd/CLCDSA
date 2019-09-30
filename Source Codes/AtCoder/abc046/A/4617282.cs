using System;
    using System.Collections.Generic;
    using System.Linq;
     
    class program{
    	static void Main(string[] args){
        	string[] input = Console.ReadLine().Split(' ');
          List<int> list  = new List<int>();	
          for(int i = 0;i < input.Length;i ++){
            if(!list.Exists(j => j == int.Parse(input[i])))
              list.Add(int.Parse(input[i]));
            }
          
          Console.WriteLine(list.Count);
        }
    }