//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		StringBuilder sb = new StringBuilder(sc.next());
		
		while (true) {
			sb.delete(sb.length()-1, sb.length());
			if (isGumozi(sb.toString())) {
				System.out.println(sb.length()); return;
			}
		}
		
	}
	
	
	static boolean isGumozi(String s) {
		if (s.length()%2 != 0) return false;
		if (s.substring(0, s.length()/2).equals(s.substring(s.length()/2,s.length()))) {
			return true;
		}
		return false;
	}
}