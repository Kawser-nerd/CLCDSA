//abc117-c

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		String s = sc.next();
		
//		int a = sc.nextInt(); int b = sc.nextInt();
		
		int ans = 0;
		for (int i=0; i<s.length(); i++) {
			if (s.charAt(i)=='+') ans++;
			else ans--;
		}
		
		
		System.out.println(ans);

	}
}