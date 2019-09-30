import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		StringBuilder sb = new StringBuilder();

		String s = sc.nextLine();

		for (int i = 0; i < s.length(); i++) {
			switch (s.charAt(i)) {
			case '0':
				sb.append("0");
				break;
			case '1':
				sb.append("1");
				break;
			case 'B':
				if (!sb.toString().equals("")) {
					sb.deleteCharAt(sb.length() - 1);
				}
				break;
			}
		}
		System.out.println(sb);
		sc.close();
	}
}