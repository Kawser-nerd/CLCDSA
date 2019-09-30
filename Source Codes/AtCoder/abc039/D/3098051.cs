using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		string[] arr=new string[s[0]+2];
		char[,] c=new char[s[0]+2,s[1]+2];
		char[,] b=new char[s[0]+2,s[1]+2];
		arr[0]=new string('#',s[1]+2);
		for(int i=1;i<=s[0];i++){arr[i]="#"+Console.ReadLine()+"#";}
		arr[s[0]+1]=new string('#',s[1]+2);
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[1];j++){
				if(arr[i-1][j-1].ToString()=="#"&&arr[i-1][j].ToString()=="#"&&arr[i-1][j+1].ToString()=="#"&&arr[i][j-1].ToString()=="#"&&arr[i][j].ToString()=="#"&&arr[i][j+1].ToString()=="#"&&arr[i+1][j-1].ToString()=="#"&&arr[i+1][j].ToString()=="#"&&arr[i+1][j+1].ToString()=="#"){
					c[i,j]='#';
				}
				else{c[i,j]='.';}
			}
		}
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[1];j++){
				if(c[i,j]=='#'){
					b[i-1,j-1]='#';b[i-1,j]='#';b[i-1,j+1]='#';
					b[i,j-1]='#';b[i,j]='#';b[i,j+1]='#';
					b[i+1,j-1]='#';b[i+1,j]='#';b[i+1,j+1]='#';
				}
			}
		}
		string ans="possible";
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[1];j++){
				if(b[i,j]!='#'){b[i,j]='.';}
				if(b[i,j]!=arr[i][j]){ans="impossible";goto f;}
			}
		}
		f:
		Console.WriteLine("{0}",ans);
		if(ans=="possible"){
			for(int i=1;i<=s[0];i++){
				for(int j=1;j<=s[1];j++){Console.Write("{0}",c[i,j]);}
				Console.WriteLine();
			}
		}
	}
}