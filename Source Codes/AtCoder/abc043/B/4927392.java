import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			String s = scanner.nextLine();
			StringBuilder sb = new StringBuilder();
			s.chars().forEach(c -> {
				switch (c) {
				case '0':
				case '1':
					sb.append((char) c);
					break;
				case 'B':
					if (sb.length() > 0) {
						sb.deleteCharAt(sb.length() - 1);
					}
					break;
				default:
					break;
				}
			});
			System.out.println(sb.toString());
		}
	}
}