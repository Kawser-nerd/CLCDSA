using System;
class Program{
	static int[] hf;
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int v=1005,e=4003,ans=0;
		int[] u=new int[]{-100,0,100};
		int n=1000;
		hf=new int[v];

		int[][] arr=new int[e][];
		for(int i=0;i<3;i++){
			for(int j=0;j<n;j++){arr[i*n+j]=new int[]{i+2,j+5,Math.Abs(u[i]-(j-n/2)),0};}
		}
		for(int j=0;j<n;j++){arr[3000+j]=new int[]{j+5,v,0,0};}
		arr[4000]=new int[]{1,2,0,0};
		arr[4001]=new int[]{1,3,0,0};
		arr[4002]=new int[]{1,4,0,0};

		int[] rt=new int[v+1];
		int[] h=new int[v+1];
		for(int i=1;i<=v;i++){h[i]=int.MaxValue;}
		h[1]=0;
		int aa=0,q,o;

		while(s[0]+s[1]+s[2]!=0){
			int l=0,z=0;
			bool b=true;
			while(b&&l<=v){
				l++;
				b=false;
				for(int i=0;i<e;i++){
					if(h[arr[i][0]]!=int.MaxValue&&h[arr[i][1]]>h[arr[i][0]]+arr[i][2]){
						h[arr[i][1]]=h[arr[i][0]]+arr[i][2];
						rt[arr[i][1]]=i;
						b=true;
						if(l==v){hf[arr[i][1]]=1;z++;}
					}
				}
			}
			q=v;
			while(rt[q]<4000){
				int bb=arr[rt[q]][0];
				if(arr[rt[q]][3]==0){
					arr[rt[q]][2]=-arr[rt[q]][2];
					o=arr[rt[q]][0];
					arr[rt[q]][0]=arr[rt[q]][1];
					arr[rt[q]][1]=o;
					arr[rt[q]][3]++;
				}
				else{arr[rt[q]][2]=1000000;arr[rt[q]][3]++;}
				q=bb;
			}
			ans+=h[v];
			s[q-2]--;
			for(int i=1;i<=v;i++){
				h[i]=int.MaxValue;
				rt[i]=0;
			}
			if(s[0]==0){arr[4000][2]=1000000;}
			if(s[1]==0){arr[4001][2]=1000000;}
			if(s[2]==0){arr[4002][2]=1000000;}
			h[1]=0;
			aa++;
		}
		Console.WriteLine("{0}",ans);
	}
}