import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????

		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int y = 700;

		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(i) == 'o') y += 100;
		}

		System.out.println(y);
	}

}