using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		char[]c=new string('0',s[0]+1).ToCharArray();
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			c[q[0]-1]=((c[q[0]-1]-'0')^1).ToString().ToCharArray()[0];
			c[q[1]]=((c[q[1]]-'0')^1).ToString().ToCharArray()[0];
		}
		int h=0;
		for(int i=0;i<s[0];i++){
			if(c[i]-'0'==1){c[i]=((c[i]-'0')^h).ToString().ToCharArray()[0];h^=1;}
			else{c[i]=((c[i]-'0')^h).ToString().ToCharArray()[0];}
		}
		Console.WriteLine("{0}",new String(c).Remove(s[0],1));
	}
}