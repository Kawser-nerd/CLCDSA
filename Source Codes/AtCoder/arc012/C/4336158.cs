using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
static class Program{
	const int mod=1000000007;
	const long o=1;
	static int[,] h=new int[19,19];
	static int f=0,g=1;
	static void Main(){
		Sc sc=new Sc();
		string[] s=new string[19];
		string ans="YES";
		int[] b=new int[10];
		for(int i=0;i<19;i++){
			s[i]=sc.S;
			int[] q=new int[10];
			for(int j=0;j<19;j++){
				if(s[i][j]!='.'){
					b[s[i][j]-111]++;
					q[s[i][j]-111]++;
					if(q[(s[i][j]-111)^9]>9){ans="NO";}
					else if(q[(s[i][j]-111)^9]>4){g=(s[i][j]-111)^9;Fu1(i,j,10-q[g]);}
					q[(s[i][j]-111)^9]=0;
				}
				else{
					if(q[0]>9||q[9]>9){ans="NO";}
					else if(q[0]>4||q[9]>4){g=q[0]>4?0:9;Fu1(i,j,10-q[g]);}
					q[0]=0;
					q[9]=0;
				}
			}
			if(q[0]>9||q[9]>9){ans="NO";}
			else if(q[0]>4||q[9]>4){g=q[0]>4?0:9;Fu1(i,19,10-q[g]);}
		}

		for(int i=0;i<19;i++){
			int[] q=new int[10];
			for(int j=0;j<19;j++){
				if(s[j][i]!='.'){
					q[s[j][i]-111]++;
					if(q[(s[j][i]-111)^9]>9){ans="NO";}
					else if(q[(s[j][i]-111)^9]>4){g=(s[j][i]-111)^9;Fu2(i,j,10-q[g]);}
					q[(s[j][i]-111)^9]=0;
				}
				else{
					if(q[0]>9||q[9]>9){ans="NO";}
					else if(q[0]>4||q[9]>4){g=q[0]>4?0:9;Fu2(i,j,10-q[g]);}
					q[0]=0;
					q[9]=0;
				}
			}
			if(q[0]>9||q[9]>9){ans="NO";}
			else if(q[0]>4||q[9]>4){g=q[0]>4?0:9;Fu2(i,19,10-q[g]);}
		}

		for(int i=4;i<19;i++){
			int[] q=new int[10];
			int j=0,k=i;
			for(;j<19&&k>=0;j++,k--){
				if(s[j][k]!='.'){
					q[s[j][k]-111]++;
					if(q[(s[j][k]-111)^9]>9){ans="NO";}
					else if(q[(s[j][k]-111)^9]>4){g=(s[j][k]-111)^9;Fu3(j,k,10-q[g]);}
					q[(s[j][k]-111)^9]=0;
				}
				else{
					if(q[0]>9||q[9]>9){ans="NO";}
					else if(q[0]>4||q[9]>4){g=q[0]>4?0:9;Fu3(j,k,10-q[g]);}
					q[0]=0;
					q[9]=0;
				}
			}
			if(q[0]>9||q[9]>9){ans="NO";}
			else if(q[0]>4||q[9]>4){g=q[0]>4?0:9;Fu3(j,k,10-q[g]);}
		}
		for(int i=1;i<15;i++){
			int[] q=new int[10];
			int j=i,k=18;
			for(;j<19&&k>=0;j++,k--){
				if(s[j][k]!='.'){
					q[s[j][k]-111]++;
					if(q[(s[j][k]-111)^9]>9){ans="NO";}
					else if(q[(s[j][k]-111)^9]>4){g=(s[j][k]-111)^9;Fu3(j,k,10-q[g]);}
					q[(s[j][k]-111)^9]=0;
				}
				else{
					if(q[0]>9||q[9]>9){ans="NO";}
					else if(q[0]>4||q[9]>4){g=q[0]>4?0:9;Fu3(j,k,10-q[g]);}
					q[0]=0;
					q[9]=0;
				}
			}
			if(q[0]>9||q[9]>9){ans="NO";}
			else if(q[0]>4||q[9]>4){g=q[0]>4?0:9;Fu3(j,k,10-q[g]);}
		}

		for(int i=14;i>=0;i--){
			int[] q=new int[10];
			int j=i,k=0;
			for(;j<19&&k<19;j++,k++){
				if(s[k][j]!='.'){
					q[s[k][j]-111]++;
					if(q[(s[k][j]-111)^9]>9){ans="NO";}
					else if(q[(s[k][j]-111)^9]>4){g=(s[k][j]-111)^9;Fu4(k,j,10-q[(s[k][j]-111)^9]);}
					q[(s[k][j]-111)^9]=0;
				}
				else{
					if(q[0]>9||q[9]>9){ans="NO";}
					else if(q[0]>4||q[9]>4){g=q[0]>4?0:9;Fu4(k,j,10-q[g]);}
					q[0]=0;
					q[9]=0;
				}
			}
			if(q[0]>9||q[9]>9){ans="NO";}
			else if(q[0]>4||q[9]>4){g=q[0]>4?0:9;Fu4(k,j,10-q[g]);}
		}
		for(int i=1;i<15;i++){
			int[] q=new int[10];
			int j=i,k=0;
			for(;j<19&&k<19;j++,k++){
				if(s[j][k]!='.'){
					q[s[j][k]-111]++;
					if(q[(s[j][k]-111)^9]>9){ans="NO";}
					else if(q[(s[j][k]-111)^9]>4){g=(s[j][k]-111)^9;Fu4(j,k,10-q[(s[j][k]-111)^9]);}
					q[(s[j][k]-111)^9]=0;
				}
				else{
					if(q[0]>9||q[9]>9){ans="NO";}
					else if(q[0]>4||q[9]>4){g=q[0]>4?0:9;Fu4(j,k,10-q[g]);}
					q[0]=0;
					q[9]=0;
				}
			}
			if(q[0]>9||q[9]>9){ans="NO";}
			else if(q[0]>4||q[9]>4){g=q[0]>4?0:9;Fu4(j,k,10-q[g]);}
		}
		int z=0;
		for(int i=0;i<19;i++){
			for(int j=0;j<19;j++){z=Math.Max(z,h[i,j]);}
		}
		if(Math.Abs(b[0]-b[9])>1){ans="NO";}
		if(f!=z){ans="NO";}
		if(b[9]>b[0]){ans="NO";}
		if(f>0&&g==0&&b[0]-b[9]!=1){ans="NO";}
		if(f>0&&g==9&&b[0]!=b[9]){ans="NO";}
		Console.WriteLine(ans);
	}
	static void Fu1(int i,int j,int p){
		f++;
		for(int k=j-(5-p)-1;k>j-6;k--){h[i,k]++;}
	}
	static void Fu2(int i,int j,int p){
		f++;
		for(int k=j-(5-p)-1;k>j-6;k--){h[k,i]++;}
	}
	static void Fu3(int i,int j,int p){
		f++;
		j+=(5-p)+1;
		for(int k=i-(5-p)-1;k>i-6;k--,j++){h[k,j]++;}
	}
	static void Fu4(int i,int j,int p){
		f++;
		j-=(5-p)+1;
		for(int k=i-(5-p)-1;k>i-6;k--,j--){h[k,j]++;}
	}
}

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public int[] Ia2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}