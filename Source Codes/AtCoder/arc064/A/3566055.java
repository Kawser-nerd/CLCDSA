import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long x = sc.nextLong();
		long[] a = new long[n];
		long s = 0;
		for(int i=0; i<n; i++){
			a[i] = sc.nextLong();
			s += a[i];
		}
		a[0] = Math.min(a[0], x);
		for(int i=1; i<n; i++){
			a[i] = Math.min(a[i], x-a[i-1]);
			s -= a[i];
		}
		System.out.println(s-a[0]);
	}
}