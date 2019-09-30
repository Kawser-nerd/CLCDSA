//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		String s = sc.next();
		int[] ar = new int[26];
		for (int i=0; i<s.length(); i++) ar[(int)s.charAt(i)-97]++;
		for (int i=0; i<26; i++) {
			if (ar[i] > 1) {
				System.out.println("no");
				return;
			}
		}
		System.out.println("yes");
		
		
	}
}