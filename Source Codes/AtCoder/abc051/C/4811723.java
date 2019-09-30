import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		int sx = sc.nextInt();
		int sy = sc.nextInt();
		int tx = sc.nextInt();
		int ty = sc.nextInt();
		StringBuilder sb = new StringBuilder();

		// 1/2
		for (int k = 0; k < ty - sy; k++) {
			sb.append("U");
		}

		for (int k = 0; k < tx - sx; k++) {
			sb.append("R");
		}

		for (int k = 0; k < ty - sy; k++) {
			sb.append("D");
		}

		for (int k = 0; k < tx - sx; k++) {
			sb.append("L");
		}

		// 2/2
		sx--;
		sb.append("L");

		for (int k = 0; k < ty + 1 - sy; k++) {
			sb.append("U");
		}

		for (int k = 0; k < tx - sx; k++) {
			sb.append("R");
		}

		sb.append("D");


		sb.append("R");

		for (int k = 0; k < ty+1 - sy; k++) {
			sb.append("D");
		}

		for (int k = 0; k < tx - sx; k++) {
			sb.append("L");
		}

		sb.append("U");

		System.out.println(sb);
	}
}