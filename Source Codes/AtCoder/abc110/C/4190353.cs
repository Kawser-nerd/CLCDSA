using System;
using  System.Linq;

public class Test
{
	public static void Main()
	{
bool flag = true;
		var s = Console.ReadLine().ToCharArray().Select(c=>c-'a'+1).ToArray();
		var t = Console.ReadLine().ToCharArray().Select(c=>c-'a'+1).ToArray();
int[] ToReplace = new int[27];
int[] FromReplace = new int[27];
if(s.Length==t.Length){
                for(int i=0;i<s.Length;i++){
                   if(ToReplace[s[i]] == 0)
ToReplace[s[i]] = t[i];
                   if(FromReplace[t[i]] == 0)
FromReplace[t[i]] = s[i];
if(ToReplace[s[i]] != t[i] || FromReplace[t[i]] != s[i]){
flag = false;
}
                }
}
  Console.WriteLine(flag?"Yes":"No");
	}
}