//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int n = sc.nextInt(); int m = sc.nextInt();
		int[] city = new int[n];
		for (int i=0; i<m; i++) {
			city[sc.nextInt()-1]++; city[sc.nextInt()-1]++;
		}
		
		for (int i=0; i<n; i++) {
			System.out.println(city[i]);
		}
		
	}
}