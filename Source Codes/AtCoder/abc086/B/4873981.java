import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();

		int b = sc.nextInt();

		int bLen = String.valueOf(b).length();

		int c = a*(int)Math.pow(10, bLen) + b;

		boolean ans = false;

		for(int i=1;;i++) {

			if(i*i>c) break;

			if(i*i==c) {

				ans = true;

				break;
			}
		}

		if(ans) System.out.println("Yes");

		else System.out.println("No");
	}

}