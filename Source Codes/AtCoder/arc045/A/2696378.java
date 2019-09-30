import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String[] str = in.nextLine().split(" ");
		int len = str.length;

		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < len; i++) {
			char a = str[i].charAt(0);
			char out = 0;
			if (a == 'L') {
				out = '<';
			} else if (a == 'R') {
				out = '>';
			} else if (a == 'A') {
				out = 'A';
			}
			if (i > 0) {
				sb.append(" ");
			}
			sb.append(out);
		}

		System.out.println(sb.toString());
	}

}