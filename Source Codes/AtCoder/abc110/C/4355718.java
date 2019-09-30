import java .util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String S = sc.nextLine();
		String T = sc.nextLine();
		
		Map<Character, Character> map = new HashMap<Character, Character>();
		for(int i = 0; i < S.length(); i++) {
			Character str1 = S.charAt(i);
			Character str2 = T.charAt(i);
			if(!map.containsKey(str1) && !map.containsValue(str2)) {
				map.put(str1, str2);
			} else {
				if(!str2.equals(map.get(str1))) {
					System.out.println("No");
					return;
				}
			}
		}
		
		System.out.println("Yes");
	}
}