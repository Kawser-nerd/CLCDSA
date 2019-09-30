import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int sx = sc.nextInt();
		int sy = sc.nextInt();
		int tx = sc.nextInt();
		int ty = sc.nextInt();
		sc.close();

		StringBuilder sb = new StringBuilder();

		// 1????
		int cnt = ty - sy;
		for (int i = 0; i < cnt; i++) {
			sb.append('U');
		}
		cnt = tx - sx;
		for (int i = 0; i < cnt; i++) {
			sb.append('R');
		}

		// 1????
		cnt = ty - sy;
		for (int i = 0; i < cnt; i++) {
			sb.append('D');
		}
		cnt = tx - sx;
		for (int i = 0; i < cnt; i++) {
			sb.append('L');
		}

		// 2????
		sb.append('L');
		cnt = ty - sy + 1;
		for (int i = 0; i < cnt; i++) {
			sb.append('U');
		}
		cnt = tx - sx + 1;
		for (int i = 0; i < cnt; i++) {
			sb.append('R');
		}
		sb.append('D');

		// 2????
		sb.append('R');
		cnt = ty - sy + 1;
		for (int i = 0; i < cnt; i++) {
			sb.append('D');
		}
		cnt = tx - sx + 1;
		for (int i = 0; i < cnt; i++) {
			sb.append('L');
		}
		sb.append('U');

		System.out.println(sb.toString());
	}
}