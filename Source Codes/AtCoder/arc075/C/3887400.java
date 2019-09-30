import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long k=sc.nextLong();
		long[] a=new long[n];
		for(int i=0;i<n;i++) a[i]=sc.nextLong();
		
		long[] b=new long[n+1];
		for(int i=0;i<n;i++) b[i+1]=b[i]+a[i];
		
		for(int i=1;i<=n;i++) b[i]-=k*i;
		System.out.println(inversion(b));
	}
	static long inversion(long[] a){
		int n=a.length;
		HashMap<Long,Integer> map=new HashMap<>();
		long[] b=Arrays.copyOf(a,a.length);
		Arrays.sort(b);
		int num=0;
		for(int i=0;i<n;i++){
			if(!map.containsKey(b[i])) map.put(b[i],num++);
		}
		
		int[] c=new int[n];
		for(int i=0;i<n;i++){
			c[i]=map.get(a[i]);
		}
		BIT bit=new BIT(n);
		
		long res=0;
		for(int i=0;i<n;i++){
			res+=bit.sum(c[i]);
			bit.add(c[i],1);
		}
		return res;
	}
}
class BIT{
	int size;
	long[] arr;
	public BIT(int n){//0 to n
		size=n+1;
		arr=new long[size+1];
	}
	void add(int i,long v){//0 indexed
		i++;
		for(int x=i;x<=size;x+=(x & (-x))) arr[x]+=v;
	}
	long sum(int i){//h[0]+...+h[i]
		i++;//arr[1]+...+arr[i+1]
		long res=0;
		for(int x=i;x>0;x-=(x & (-x))) res+=arr[x];
		return res;
	}
}