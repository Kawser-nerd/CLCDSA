using System;
public class Hello{
    public static void Main(){
        // Your code here!
        string[] nl = Console.ReadLine().Split(' ');
      	int n = int.Parse(nl[0]);
//      	int l = int.Parse(nl[1]);
      	string[] word = new string[n];
      	for(int i=0;i<n;i++){
          word[i] = Console.ReadLine();
        }
        Array.Sort(word);
        
        for(int i=0;i<n;i++){
          Console.Write("{0}",word[i]);
        }
      	Console.WriteLine("");
    }
}