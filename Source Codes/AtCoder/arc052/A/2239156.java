import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String ans = new String();
		for(char c : s.toCharArray()) {
			if(Character.isDigit(c)) ans += c;
		}
		System.out.println(ans);
	}
}