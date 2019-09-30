import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a=new long[3*n]; 
		for(int i=0;i<a.length;i++) a[i]=sc.nextLong();
		
		long score=0;
		PriorityQueue<Long> leftQueue=new PriorityQueue<>();
		PriorityQueue<Long> rightQueue=new PriorityQueue<>(Collections.reverseOrder());		
		for(int i=0;i<n;i++){
			leftQueue.add(a[i]);
			score+=a[i];
			rightQueue.add(a[2*n+i]);
			score-=a[2*n+i];
		}
		
		long[] ds=new long[n+1];
		long d=0;
		for(int i=1;i<=n;i++){
			leftQueue.add(a[n+i-1]);
			d+=a[n+i-1]-leftQueue.poll();
			ds[i]+=d;
		}
		d=0;
		for(int i=1;i<=n;i++){
			rightQueue.add(a[2*n-i]);
			d+=rightQueue.poll()-a[2*n-i];
			ds[n-i]+=d;
		}

		long maxds=ds[0];
		for(int i=1;i<=n;i++) maxds=Math.max(maxds, ds[i]);
		
		System.out.println(score+maxds);
	}
}