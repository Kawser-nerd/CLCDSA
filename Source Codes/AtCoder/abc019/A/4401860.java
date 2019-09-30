import java.util.Scanner;

public class Main {
	public static void main(String args[]) {

		Scanner scan = new Scanner (System.in);

		int age1 = scan.nextInt();
		int age2 = scan.nextInt();
		int age3 = scan.nextInt();

		System.out.println(med(age1,age2,age3));


	}

	//3????????????
	static int med(int a,int b,int c) {
		if(a>=b) {
			if(b >= c) {
				return b;
			}else if(a <= c) {
				return a;
			}else {
				return c;
			}
		}
		else if(a > c) {
			return a;
		}
		else if(b > c) {
			return c;
		}
		else {
			return b;
		}
	}

}