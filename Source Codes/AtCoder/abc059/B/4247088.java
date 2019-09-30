import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String a = sc.next();
		String b = sc.next();
		
		if (a.length() == b.length()) {
			for (int i = 0; i < a.length(); i++) {
				int ai = Character.getNumericValue(a.charAt(i));
				int bi = Character.getNumericValue(b.charAt(i));
				if (ai != bi) {
					System.out.println(ai > bi ? "GREATER" : "LESS");
					return;
				}
			}
		} else {
			System.out.println(a.length() > b.length() ? "GREATER" : "LESS");
			return;
		}
		
		System.out.println("EQUAL");
	}
	
	
}