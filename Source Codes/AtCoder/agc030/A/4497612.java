import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();

		int delicious = 0;
		boolean poison = false;

		while(c > 0) {

			if(poison) 	break;

			c--;
			delicious++;

			poison = true;

			if(b > 0) {
				b--;
				delicious++;
				poison = false;
			} else if(a > 0) {
				a--;
				poison = false;
			}
		}

		delicious += b;
		System.out.println(delicious);
	}
}