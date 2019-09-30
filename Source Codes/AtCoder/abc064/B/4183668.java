//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int[] ar = new int[n];
		for (int i=0; i<n; i++) ar[i] = sc.nextInt();
		Arrays.sort(ar);
		int sum = 0;
		for (int i=0; i<n-1; i++) {
			sum += ar[i+1] - ar[i];
		}
		System.out.println(sum);
		
		
	}
}