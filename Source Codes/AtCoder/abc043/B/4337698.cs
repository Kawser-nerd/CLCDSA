using System;
using System.Collections.Generic;
class program{
	static void Main (string[] args){
    	string input = Console.ReadLine();
      	List<char> output = new List<char>();
      	for(int i = 0; i < input.Length;i ++){
        	switch(input[i]){
              case '0':
   				output.Add('0');
                break;
              case '1':
                output.Add('1');
                break;
              default:
                if(output.Count > 0)output.RemoveAt(output.Count - 1);
                break;
            }
        }
      char[] final = new char[output.Count];
      for(int i = 0;i < output.Count;i ++){
      	final[i] = output[i];
      }
      
      Console.WriteLine(final);
    }
}