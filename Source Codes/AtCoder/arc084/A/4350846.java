import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int[] A = new int[n], B = new int[n], C = new int[n];
		for (int i=0; i<n; i++) A[i] = sc.nextInt();
		for (int i=0; i<n; i++) B[i] = sc.nextInt();
		for (int i=0; i<n; i++) C[i] = sc.nextInt();
		Arrays.sort(A); Arrays.sort(C);
		
		long ans = 0L;
		for (int i=0; i<n; i++) {
			long a = binarySearchLB(A, B[i]);
			long c = binarySearchUB(C, B[i]);
			c = n - c;
			ans += a * c;
		}

		System.out.println(ans);



	}

	static int binarySearchLB (int[] ar, int t) {
		int L = 0;
		int R = ar.length;
		while (L < R) {
			int M = (L+R) / 2;
			if (t <= ar[M]) R = M;
			else L = M+1;
		}
		return L;
	}


	static int binarySearchUB (int[] ar, int t) {
		int L = 0;
		int R = ar.length;
		while (L < R) {
			int M = (L+R) / 2;
			if (t >= ar[M]) L = M+1;
			else R = M;
		}
		return L;
	}

}