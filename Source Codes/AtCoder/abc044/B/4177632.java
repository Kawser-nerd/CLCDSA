//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {

		String w = sc.next();
		int[] ar = new int[26];
		for (int i=0; i<w.length(); i++) {
			ar[w.charAt(i) - 97]++;
		}
		
		for (int i=0; i<26; i++) {
			if (ar[i]%2 != 0) {
				System.out.println("No");
				return;
			}
		}
		
		System.out.println("Yes");
		
	}
}