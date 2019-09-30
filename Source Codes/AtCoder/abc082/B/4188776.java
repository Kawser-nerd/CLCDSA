//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();
		
		Arrays.sort(t);
		String t2 = new StringBuilder(String.valueOf(t)).reverse().toString();
		
		Arrays.sort(s);
		String s2 = String.valueOf(s);
		
		System.out.println(s2.compareTo(t2)<0?"Yes":"No");
		
		
	}
}