//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int x = sc.nextInt();
		int n = (int)Math.sqrt(x);
		
		int max = 0;
		for (int i=1; i<=n; i++) {
			for (int j=2; j<=10; j++) {
				if (Math.pow(i,j) > x) {
					max = Math.max(max, (int)Math.pow(i, j-1));
					break;
				}
			}
		}
		
		System.out.println(x==1?1:max);
		
	}
}