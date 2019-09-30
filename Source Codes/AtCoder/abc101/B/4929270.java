import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		String N = reader.next();
		int num = 0;
		for (int i = 0; i < N.length(); i++) {
			char ch = N.charAt(i);
			num += Character.getNumericValue(ch);
		}
		if (Integer.parseInt(N) % num == 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}



		reader.close();
	}
}