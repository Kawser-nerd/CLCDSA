import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String result = "";
		for (int i = 0; i < 3; i++) {
			result += sc.next().charAt(i);
		}

		System.out.println(result);

		sc.close();
	}

}