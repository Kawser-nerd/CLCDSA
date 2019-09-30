//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		Long[] ar = new Long[n+1];
		ar[0] = 2L;
		ar[1] = 1L;
		
		for (int i=2; i<n+1; i++) {
			ar[i] = ar[i-1] + ar[i-2];
		}
		
		System.out.println(ar[n]);
		
	}
}