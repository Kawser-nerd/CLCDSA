//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		String a = sc.next();
		String b = sc.next();
		
		String ans = "EQUAL";
		if (a.length() > b.length()) ans = "GREATER";
		else if (a.length() < b.length()) ans = "LESS";
		else {
			for (int i=0; i<a.length(); i++) {
				if (a.charAt(i)-'0' > b.charAt(i)-'0') {
					ans = "GREATER";
					break;
				}
				else if (a.charAt(i)-'0' < b.charAt(i)-'0') {
					ans = "LESS";
					break;
				}
			}
		}
		System.out.println(ans);
		
	}
}