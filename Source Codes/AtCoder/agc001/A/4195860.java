//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = 2*sc.nextInt();
		int[] ar = new int[n];
		for (int i=0; i<n; i++) ar[i] = sc.nextInt();
		Arrays.sort(ar);
		int ans = 0;
		for (int i=0; i<n-1; i+=2) {
			ans += Math.min(ar[i],ar[i+1]);
		}
		System.out.println(ans);
		
		
	}
}