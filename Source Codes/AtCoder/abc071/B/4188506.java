//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		String s = sc.next();
		boolean[] alphabet = new boolean[26];
		for (int i=0; i<s.length(); i++) {
			alphabet[s.charAt(i)-97] = true;
		}
		
		for (int i=0; i<26; i++) {
			if (alphabet[i] == false) {
				char c = (char)(i+97);
				System.out.println(c);
				return;
			}
		}
		
		System.out.println("None");
		
		
	}
}