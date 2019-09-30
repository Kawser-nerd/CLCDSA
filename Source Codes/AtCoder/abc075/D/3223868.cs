using System;
class Program{
	static int[] s;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[][] arr=new long[2][];
		arr[0]=new long[s[0]];
		arr[1]=new long[s[0]];
		long ans=long.MaxValue;
		for(int i=0;i<s[0];i++){
			long[] q=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
			arr[0][i]=q[0];
			arr[1][i]=q[1];
		}

		var h1=new System.Collections.Generic.SortedSet<long>(arr[0]);
		var h2=new System.Collections.Generic.SortedSet<long>(arr[1]);
		long[] x=new long[h1.Count];
		long[] y=new long[h2.Count];
		h1.CopyTo(x,0);
		h2.CopyTo(y,0);

		for(int i=0;i<x.Length-1;i++){
			for(int j=i+1;j<x.Length;j++){
				for(int k=0;k<y.Length-1;k++){
					for(int l=k+1;l<y.Length;l++){
						int p=0;
						for(int m=0;m<s[0];m++){
							if(arr[0][m]>=x[i]&&arr[0][m]<=x[j]&&arr[1][m]>=y[k]&&arr[1][m]<=y[l]){
								p++;
								if(p==s[1]){
									ans=Math.Min(ans,(x[j]-x[i])*(y[l]-y[k]));
									break;
								}
							}
						}
					}
				}
			}
		}
		Console.WriteLine("{0}",ans);
	}
}