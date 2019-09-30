import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String S = sc.next();
		String T = sc.next();

		Map<Character, Integer> mapS = new HashMap<>();
		Map<Character, Integer> mapT = new HashMap<>();

		int index = 0;
		for (int i = 0; i < S.length(); i++) {
			char charS = S.charAt(i);
			char charT = T.charAt(i);

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
			}
			index++;
			mapS.put(charS, index);
			mapT.put(charT, index);
		}
		System.out.println("Yes");
	}
}