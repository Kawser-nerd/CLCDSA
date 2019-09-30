import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int[] A = new int[n], B = new int[n];
		for (int i=0; i<n; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
		}
		
		
		long ans = 0;
		for (int i=n-1; i>=0; i--) {
			long temp = (A[i] + ans) % B[i];
			ans += temp==0? 0 : B[i] - temp;
		}
		
		System.out.println(ans);
		
//		long ans = 0;
//		for (int i=0; i<n; i++) {
//			long a = sc.nextLong();
//			long b = sc.nextLong();
//			System.out.println(b*(a/b+1));
//			ans += b*(a/b+1) - a;
//		}
//		System.out.println(ans);
		
	}
}