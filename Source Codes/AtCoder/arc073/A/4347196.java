import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt(), t = sc.nextInt();
		int[] ar = new int[n+1];
		long ans = 0L;
		for (int i=0; i<n; i++) {
			ar[i] = sc.nextInt();
		}
		ar[n] = ar[n-1] + t;
		for (int i=0; i<n; i++) {
			ans += Math.min(ar[i+1]-ar[i], t);
		}
		System.out.println(ans);
		
	}
}