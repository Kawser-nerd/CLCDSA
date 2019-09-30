import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] st = sc.nextLine().split(" ");
		sc.close();
		int[] n = new int[4];
		for (int i = 0; i < 4; i++) {
			n[i] = Integer.parseInt(st[i]);
		}
		double tk = (double) n[1] / n[0];
		double ao = (double) n[3] / n[2];
		if (tk == ao) {
			System.out.println("DRAW");
		} else {
			System.out.println(tk > ao ? "TAKAHASHI" : "AOKI");
		}
	}
}