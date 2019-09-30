using System;
class Program
{
	static void Main(string[] args){
		// ?????
		int c=0;
		string a = Console.ReadLine();
                string b= Console.ReadLine();
                string po="atcoder@";
	        for (int i=0;i<a.Length;i++){
                    if(a[i]=='@'&&CountChar(po,b[i])==0){
                          Console.WriteLine("You will lose");
                          return;
                    }else if(b[i]=='@'&&CountChar(po,a[i])==0){
                          Console.WriteLine("You will lose");
                          return;
                    }else if(a[i]!=b[i]&&a[i]!='@'&&b[i]!='@'){
                          Console.WriteLine("You will lose");
                          return;
                    }
                }
                Console.WriteLine("You can win");
	}
	public static int CountChar(string s, char c) {
            return s.Length - s.Replace(c.ToString(), "").Length;
         }
}