import java.util.Scanner;

public class Main {
	//private static Scanner stdIn;

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		
		int a = stdIn.nextInt();
		int b = stdIn.nextInt();
		int n = 0;
		int sa = (a - b > 0) ?  a - b : b - a;
		while(sa != 0) {
			if(sa >= 8)
				a = (a - b > 0)? a - 10 : a + 10;
			else if(sa >= 3)
				a = (a - b > 0) ? a - 5 : a + 5;
			else
				a = (a - b > 0) ? a - 1 : a + 1;
			sa = (a - b > 0) ?  a - b : b - a;
			n++;
		}
		System.out.println(n);
	}
}