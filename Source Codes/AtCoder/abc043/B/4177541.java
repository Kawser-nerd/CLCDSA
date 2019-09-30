//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		String s = sc.next();
		StringBuilder sb = new StringBuilder();
		for (int i=0; i<s.length(); i++) {
			if (s.charAt(i)=='0' || s.charAt(i)=='1') sb.append(s.charAt(i));
			else if (sb.length() != 0)sb.delete(sb.length()-1,sb.length());
		}
		
		System.out.println(sb);
	}
}