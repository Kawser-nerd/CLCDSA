import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String komugiko = scanner.nextLine();
		scanner.close();

		String xStr = "0", yStr = "0";
		for (int i = 0; i < komugiko.length(); i++) {
			if (komugiko.charAt(i) == ' ') {
				xStr = komugiko.substring(0, i);
				yStr = komugiko.substring(i+1);
				break;
			}
		}

		int x = Integer.parseInt(xStr);
		int y = Integer.parseInt(yStr);

		int takoyaki = y / x;

		System.out.println(takoyaki);
	}

}