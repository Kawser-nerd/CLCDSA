import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		String S = "";

		boolean ans = false;

		for(int i=0;i<N;i++) {

			S = sc.next();

			if(S.equals("Y")) {

				ans = true;

				break;
			}
		}

		if(ans) System.out.println("Four");

		else System.out.println("Three");
	}

}