import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		int L = s.length();
		boolean update = true;
		String[] words = {"dream", "dreamer", "erase", "eraser"};
		while(update) {
			update = false;
			for(String word : words) {
				if(L>=word.length() && s.substring(L-word.length(), L).equals(word)) {
					L -= word.length();
					update = true;
				}
			}
		}
		
		System.out.println(L==0 ? "YES" : "NO");
		sc.close();
	}
}