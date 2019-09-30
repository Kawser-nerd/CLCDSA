//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		String s = sc.next();
		StringBuilder sb = new StringBuilder();
		for (int i=0; i<s.length(); i++) {
			if (i%2 == 0) sb.append(s.charAt(i));
		}
		
		System.out.println(sb);
		
		
		
	}
}