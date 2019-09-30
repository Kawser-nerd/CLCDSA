import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int from = scn.nextInt();
		int to = scn.nextInt();

		int ans = (to-from)+1;

		System.out.println(ans);
	}

}