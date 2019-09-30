import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] a=new int[n],b=new int[n];
		for(int i=0;i<n;i++){
			a[i]=sc.nextInt();
			b[i]=sc.nextInt();
		}
		
		int[] c=new int[2*n];
		for(int i=0;i<n;i++)c[i]=a[i];
		for(int i=n;i<n*2;i++)c[i]=b[i-n];
		
		Integer[] ind=new Integer[2*n];
		for(int i=0;i<2*n;i++)ind[i]=i;
		Arrays.sort(ind,(x,y)->c[x]-c[y]);
		
		long res=0;
		
		int[] d=new int[n];
		for(int i=0;i<n;i++) d[i]=ind[i];
		res=check(c,d);
		if(res>=0){
			pl(res);
			return;
		}
		
		d[n-1]=ind[n];
		res=check(c,d);
		if(res>=0){
			pl(res);
			return;
		}
		
		res=0;
		for(int i=0;i<n+2;i++)res+=c[ind[i]];
		if(c[ind[n-1]]+c[ind[n]]<c[ind[n-2]]+c[ind[n+1]]){
			res-=c[ind[n-2]]+c[ind[n+1]];
		}else{
			res-=(c[ind[n-1]]+c[ind[n]]);
		}
		pl(res);
	}
	static void pl(Object o){System.out.println(o);}
	static long check(int[] c,int[] d){
		int n=d.length;
		int[] h=new int[n];
		for(int i=0;i<d.length;i++){
			int j=d[i];
			if(j>=n)h[j-n]+=2;
			else h[j]+=1;
		}
		int left=0,right=0,both=0,none=0;
		for(int i=0;i<n;i++){
			if(h[i]==0)none++;
			if(h[i]==1)left++;
			if(h[i]==2)right++;
			if(h[i]==3)both++;
		}
		if(both==0 && left>0 && right>0)return -1;
		
		long res=0;
		for(int i=0;i<n;i++) res+=c[d[i]];
		return res;
	}
}