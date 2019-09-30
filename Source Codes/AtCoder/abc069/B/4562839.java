import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????

		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		
		int len = s.length() - 2;
		
		System.out.println(s.substring(0, 1) + len + s.substring(s.length() - 1, s.length()));
	}

}