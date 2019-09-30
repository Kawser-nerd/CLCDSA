import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		String S = reader.next();
		String T = reader.next();
		String ans = "No";
		
		for (int i = 0; i < S.length(); i ++) {
			if (S.equals(T)) {
				ans = "Yes";
				break;
			}
			S = S.charAt(S.length()-1) + S.substring(0, S.length()-1);
		}
		

		reader.close();
		System.out.print(ans);
	}
}