import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		try (Scanner scTmp = new Scanner(System.in);) {

			// Java 8
			String sTmp = scTmp.nextLine();
			StringBuilder sb = new StringBuilder();
			sTmp.chars().forEach(cTmp -> {
				switch (cTmp) {
				case '0':
					sb.append("0");
					break;
				case '1':
					sb.append("1");
					break;
				case 'B':
					if (sb.length() > 0) {
						sb.deleteCharAt(sb.length() - 1);
					}
					break;
				}
			});

			System.out.println(sb.toString());
		}
	}
}