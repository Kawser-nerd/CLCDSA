import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		sc.close();

		String[] inputs = input.split("[+]");
		int ct = 0;

		for (int i = 0; i < inputs.length; i++) {

			if (!inputs[i].contains("0")) {
				ct++;
			}
		}

		System.out.println(ct);
	}

}