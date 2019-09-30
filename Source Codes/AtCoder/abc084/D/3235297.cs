using System;
class Program{
	static void Main(){
		int[] b=new int[100001];
		int[] h=new int[100001];
		for(int i=2;i<100001;i++){
			if(b[i]==0){
				for(int j=i*2;j<100001;j+=i){b[j]=-1;}
			}
			b[i]++;
			h[i]=(b[i]&b[(i+1)/2])+h[i-1];
		}

		int n=int.Parse(Console.ReadLine());
		for(int i=0;i<n;i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			Console.WriteLine("{0}",h[q[1]]-h[q[0]-1]);
		}
	}

}