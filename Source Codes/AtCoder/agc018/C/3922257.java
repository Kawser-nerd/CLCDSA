import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int x=sc.nextInt(),y=sc.nextInt(),z=sc.nextInt();
		long[] a=new long[x+y+z],b=new long[x+y+z],c=new long[x+y+z];
		int n=x+y+z;
		long res=0;
		for(int i=0;i<n;i++){
			a[i]=sc.nextLong();
			b[i]=sc.nextLong();
			c[i]=sc.nextLong();
			res+=a[i];
			b[i]-=a[i];
			c[i]-=a[i];
		}
		Integer[] ind=new Integer[n];
		for(int i=0;i<n;i++) ind[i]=i;
		Arrays.sort(ind,(s,w)-> Long.signum((b[s]-c[s])-(b[w]-c[w])));
		
		long[] nb=new long[n],nc=new long[n];
		for(int i=0;i<n;i++){
			nb[i]=b[ind[i]];
			nc[i]=c[ind[i]];
		}
		
		long[] cdp=new long[n], bdp=new long[n];
		Arrays.fill(cdp,Long.MIN_VALUE/10);
		Arrays.fill(bdp,Long.MIN_VALUE/10);
		PriorityQueue<Long> queue=new PriorityQueue<>();
		long sum=0;
		for(int i=0;i<n-y;i++){
			sum+=nc[i];
			if(i<z){
				queue.add(nc[i]);
			}else{
				queue.add(nc[i]);
				sum-=queue.poll();
			}
			cdp[i]=sum;
		}
		
		sum=0;
		queue=new PriorityQueue<>();
		for(int i=n-1;i>=z;i--){
			sum+=nb[i];
			if(i>n-1-y){
				queue.add(nb[i]);
			}else{
				queue.add(nb[i]);
				sum-=queue.poll();
			}
			bdp[i]=sum;
		}
		
		long max=Long.MIN_VALUE;
		for(int i=0;i<n-1;i++){
			long v=cdp[i]+bdp[i+1];
			max=Math.max(max,v);
		}
		System.out.println(res+max);
	}
}