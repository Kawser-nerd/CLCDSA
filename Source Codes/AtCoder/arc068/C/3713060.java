import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int[][] a=new int[n][2];
		for(int i=0;i<n;i++){
			a[i][0]=sc.nextInt()-1;
			a[i][1]=sc.nextInt();
		}
		Arrays.sort(a,(x,y)->(x[1]-x[0])-(y[1]-y[0]));
		
		int right=0;
		BIT bit=new BIT(m+2);
		for(int i=1;i<=m;i++){
			while((right<n) && (a[right][1]-a[right][0])<i){
				bit.add(a[right][1]+2,-1);
				bit.add(a[right][0]+2,1);
				right++;
			}
			int res=n-right;
			
			for(int j=i;j<=m;j+=i) res+=(bit.sum(j+1));
			pl(res);
		}
	}
	static void pl(Object o){System.out.println(o);}
}
class BIT{
	int n;
	long[] arr;
	public BIT(int n){
		this.n=n;
		arr=new long[n+1];
	}
	void add(int a,long v){
		for(int x=a;x<=n;x+=(x&(-x))) arr[x]+=v;
	}
	long sum(int a){
		long res=0;
		for(int x=a;x>0;x-=(x&(-x))) res+=arr[x];
		return res;
	}
}