import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);

		String str1 = sc.nextLine();
		String str2 = sc.nextLine();

		Map<Character,Character> c = new HashMap<Character,Character>();
		for(int i=0;i<str1.length();i++) {
			char c1 = str1.charAt(i);
			char c2 = str2.charAt(i);

			if(c.containsKey(c1)) {
				char temp = c.get(c1);
				if(c2 != temp) {
					System.out.println("No");
					return;
				}
			}else if(c.containsValue(c2)) {
				System.out.println("No");
				return;
			}else {
				c.put(c1, c2);
			}
		}
		System.out.println("Yes");
	}
}