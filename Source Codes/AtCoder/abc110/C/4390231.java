import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {

		String s = sc.next(), t = sc.next();
		HashMap<Character, Character> S = new HashMap<>();
		HashMap<Character, Character> T = new HashMap<>();
		
		for (int i=0; i<s.length(); i++) {
			char a = s.charAt(i);
			char b = t.charAt(i);
			
			if (S.containsKey(a)) {
				if (S.get(a) != b) {
					System.out.println("No");
					return;
				}
			}
			else {
				S.put(a, b);
			}
			
			if (T.containsKey(b)) {
				if (T.get(b) != a) {
					System.out.println("No");
					return;
				}
			}
			else {
				T.put(b, a);
			}
		}
		
		System.out.println("Yes");
		
		
	}
}