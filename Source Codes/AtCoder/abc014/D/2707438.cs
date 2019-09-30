using System;
class Program{
	static int ans;
	static int g;
	static int[][] arr;
	static int[,] fk;
	static void Main(string[] args){
		int s=int.Parse(Console.ReadLine());
		arr=new int[s+1][];
		fk=new int[s+1,18];

		for(int i=0;i<arr.Length;i++){arr[i]=new int[1];}

		for (int i=1;i<s;i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			Array.Resize(ref arr[q[0]],arr[q[0]].Length+1);
			arr[q[0]][arr[q[0]].Length-1]=q[1];

			Array.Resize(ref arr[q[1]],arr[q[1]].Length+1);
			arr[q[1]][arr[q[1]].Length-1]=q[0];
        }

		fu2(1,0,0);

		int sm=int.Parse(Console.ReadLine());
		for (int h=0;h<sm;h++){
			int[] r=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			int sa=fk[r[0],0]-fk[r[1],0];
			int sal;
			int c=r[0];
			int d=r[1];
			if(sa!=0){
				if(sa<0){
					sa=System.Math.Abs(sa);
					c=r[1];
					d=r[0];
				}
				sal=Convert.ToString(sa,2).Length;
				for(int i=0;i<sal;i++){
					if((sa&(1<<i))>0){
						//for(int j=0;j<=i;j++){c=fk[c,i];}
						c=fk[c,i+1];
						//Console.WriteLine("t {0},{1}",i,c);
					}
				}
			}
				
			if(c==d){Console.WriteLine(sa+1);}
			else{
				while(fk[c,1]!=fk[d,1]){c=fk[c,1];d=fk[d,1];}
				Console.WriteLine(fk[r[0],0]+fk[r[1],0]-(fk[fk[c,1],0]<<1)+1);
			}	
		}
		
	}
	static void fu2(int n,int m,int hn){
		fk[n,0]=hn;
		fk[n,1]=m;
		fk[n,2]=fk[m,1];
		for(int i=3;i<18;i++){fk[n,i]=fk[fk[n,i-1],i-1];}

		for(int i=1;i<arr[n].Length;i++){
			if(arr[n][i]!=m){fu2(arr[n][i],n,hn+1);}
		}
	}
}