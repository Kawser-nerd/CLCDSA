import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		Integer[] A = new Integer[n], B = new Integer[n], C = new Integer[n];
		for (int i=0; i<n; i++) A[i] = sc.nextInt();
		for (int i=0; i<n; i++) B[i] = sc.nextInt();
		for (int i=0; i<n; i++) C[i] = sc.nextInt();
		Arrays.sort(A); Arrays.sort(C);
		
		long ans = 0L;
		for (int i=0; i<n; i++) {
			long a = ~Arrays.binarySearch(A, B[i], (x,y)->x.compareTo(y)>=0?1:-1);
			long c = n - ~Arrays.binarySearch(C, B[i], (x,y)->x.compareTo(y)>0?1:-1);
			ans += a * c;
		}
		
		System.out.println(ans);
		
	}
}