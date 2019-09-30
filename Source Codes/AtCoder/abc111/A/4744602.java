import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String n = sc.next();
		
		StringBuilder sb = new StringBuilder(n);
		
		for(int i = 0; i < n.length(); i++) {
			sb.setCharAt(i, n.charAt(i) == '1' ? '9' : '1');
		}
		
		System.out.println(sb.toString());
	}
}