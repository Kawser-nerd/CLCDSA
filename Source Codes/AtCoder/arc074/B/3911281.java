import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[] a=new long[3*n];
		for(int i=0;i<3*n;i++) a[i]=sc.nextLong();
		
		long[] aa=new long[n+1];
		long[] bb=new long[n+1];
		PriorityQueue<Long> queue1=new PriorityQueue<>();
		PriorityQueue<Long> queue2=new PriorityQueue<>((x,y)->y>x?1:-1);
		
		long sum=0;
		for(int i=0;i<n;i++){
			queue1.add(a[i]);
			sum+=a[i];
		}
		aa[0]=sum;
		for(int i=1;i<=n;i++){
			long v=queue1.poll();
			if(a[i+n-1] > v){
				queue1.add(a[i+n-1]);
				sum+=a[i+n-1]-v;
			}else{
				queue1.add(v);
			}
			aa[i]=sum;
		}
		
		sum=0;
		for(int i=2*n;i<3*n;i++){
			queue2.add(a[i]);
			sum+=a[i];
		}
		bb[0]=sum;
		for(int i=1;i<=n;i++){
			long v=queue2.poll();
			if(v > a[2*n-i]){
				queue2.add(a[2*n-i]);
				sum+=a[2*n-i]-v;
			}else{
				queue2.add(v);
			}
			bb[i]=sum;
		}
		
		long res=Long.MIN_VALUE;
		for(int i=0;i<=n;i++){
			long v=aa[i]-bb[n-i];
			res=Math.max(res,v);
		}
		System.out.println(res);
	}
}