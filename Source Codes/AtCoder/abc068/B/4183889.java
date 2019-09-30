//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int[] ar = {64,32,16,8,4,2,1};
		int n = sc.nextInt();
		for (int i=0; i<7; i++) {
			if (n >= ar[i]) {
				System.out.println(ar[i]); return;
			}
		}
		
	}
}