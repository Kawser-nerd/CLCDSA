using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		string s=Console.ReadLine();
		int ans=s.Length;
		if(s.Length%2==0){
			if(s[s.Length/2-1]!=s[s.Length/2]){ans=s.Length/2;}
			else{
				for(int i=s.Length/2;i<s.Length-1;i++){
					if(s[s.Length-i-1]!=s[s.Length-i-2]||s[i]!=s[i+1]){
						ans=i+1;
						break;
					}
				}
			}
		}
		else if(s.Length!=1){
			if(s[s.Length/2]!=s[s.Length/2-1]||s[s.Length/2]!=s[s.Length/2+1]){ans=s.Length/2+1;}
			else{
				for(int i=s.Length/2+1;i<s.Length-1;i++){
					if(s[s.Length-i-1]!=s[s.Length-i-2]||s[i]!=s[i+1]){
						ans=i+1;
						break;
					}
				}
			}
		}
		Console.WriteLine("{0}",ans);
	}
}