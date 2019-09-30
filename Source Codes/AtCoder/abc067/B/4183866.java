//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int n = sc.nextInt(); int k = sc.nextInt();
		Integer[] ar = new Integer[n];
		for (int i=0; i<n; i++) ar[i] = sc.nextInt();
		Arrays.sort(ar,Collections.reverseOrder());
		
		int sum = 0;
		for (int i=0; i<k; i++) {
			sum += ar[i];
		}
		System.out.println(sum);
		
	}
}