import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		String remain = "01234567";
		int over = 0;
		for (int i = 0; i < N; i++) {
			int num = reader.nextInt()/400;
			if (num < 8) {
				remain = remain.replace(Integer.toString(num), "");
			} else {
				over++;
			}
		}
		int min = 8 - remain.length();
		int max = min + over;
		if (min < 1) {
			min = 1;
		}

		reader.close();
		System.out.print(min + " " + max);
	}
}