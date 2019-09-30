import java.util.Scanner;

public class Main {
	static String original;
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int R = reader.nextInt();
		String ans = "";

		if (R < 1200) {
			ans = "ABC";
		} else if (R < 2800) {
			ans = "ARC";
		} else {
			ans = "AGC";
		}

		System.out.print(ans);
	}


}