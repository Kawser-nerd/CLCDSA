using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class Program{
	static void Main(string[] args){
      
      string input = Console.ReadLine();
      
      List<char> list = new List<Char>();
      
      for(int i = 0;i < input.Length;i ++){
      	if(list.Contains(input[i]))list.Remove(input[i]);
        else list.Add(input[i]);
      }
      
      if(list.Count == 0)Console.WriteLine("Yes");
      else Console.WriteLine("No");
    }
}