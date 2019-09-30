import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int h1 = scn.nextInt();
		int m1 = scn.nextInt();
		int h2 = scn.nextInt();
		int m2 = scn.nextInt();

		if(h1==h2 || h1==m2 || m1==h2 || m1==m2) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}

	}

}