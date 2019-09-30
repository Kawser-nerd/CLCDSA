//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		String s = sc.next();
		String ans = "No";
		if (s.contains("N") && s.contains("S") && s.contains("E") && s.contains("W")) {
			ans = "Yes";
		}
		else if (!s.contains("N") && !s.contains("S") && s.contains("E") && s.contains("W")) {
			ans = "Yes";
		}
		else if (s.contains("N") && s.contains("S") && !s.contains("E") && !s.contains("W")) {
			ans = "Yes";
		}
		System.out.println(ans);
	}
}