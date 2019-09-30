//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int min = Integer.MAX_VALUE;
		for (int i=1; i<=n/2; i++) {
			int temp = 0;
			String a = String.valueOf(i);
			for (int j=0; j<a.length(); j++) {
				temp += Character.getNumericValue(a.charAt(j));
			}
			String b = String.valueOf(n-i);
			for (int j=0; j<b.length(); j++) {
				temp += Character.getNumericValue(b.charAt(j));
			}
			min = Math.min(min, temp);
		}
		System.out.println(min);
		
		
	}
}