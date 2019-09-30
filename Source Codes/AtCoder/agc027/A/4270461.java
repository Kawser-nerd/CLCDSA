import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int num = sc.nextInt();
		long[] ar = new long[n];
		for (int i=0; i<n; i++) ar[i] = sc.nextInt();
		Arrays.sort(ar);
		for (int i=1; i<n; i++) ar[i] += ar[i-1];
		
		if (ar[n-1] == num) System.out.println(n);
		else {
			int ans = -1;
			for (int i=0; i<n; i++) {
				if (ar[i] <= num) ans = i;
			}
			System.out.println(ar[n-1]<num?ans:ans+1);
		}
		
	}
}