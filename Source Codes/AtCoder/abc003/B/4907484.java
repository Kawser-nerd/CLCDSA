import java.util.Scanner;

public class Main {

	private static final char[] atcoder = "atcoder".toCharArray();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		String T = sc.next();
		boolean win = true;
		for(int i = 0; i < S.length(); i++) {
			char s = S.charAt(i);
			char t = T.charAt(i);
			if(s != t && !(s == '@' && contains(t) || t == '@' && contains(s))) {
				win = false;
				break;
			}
		}
		System.out.println(win ? "You can win" : "You will lose");
	}

	public static boolean contains(char c) {
		for(int i = 0; i < atcoder.length; i++)
			if(atcoder[i] == c)
				return true;
		return false;
	}

}