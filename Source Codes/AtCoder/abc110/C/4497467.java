import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		sc.close();

		Map<Character, Integer> mapS = new HashMap<Character, Integer>();
		Map<Character, Integer> mapT = new HashMap<Character, Integer>();
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			char charS = s.charAt(i);
			char charT = t.charAt(i);
			if (mapS.containsKey(charS)) {
				if (mapT.containsKey(charT)) {
					if (!mapS.get(charS).equals(mapT.get(charT))) {
						System.out.println("No");
						return;
					}
				} else {
					System.out.println("No");
					return;
				}
			} else {
				if (mapT.containsKey(charT)) {
					System.out.println("No");
					return;
				}
				cnt++;
				mapS.put(charS, cnt);
				mapT.put(charT, cnt);
			}
		}
		System.out.println("Yes");
	}
}