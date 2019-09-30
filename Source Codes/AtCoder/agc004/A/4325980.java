import java.util.Scanner;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {

		long a = sc.nextLong(); long b = sc.nextLong(); long c = sc.nextLong();
		if (a%2==0 || b%2==0 || c%2==0) {
			System.out.println(0);
		}
		else {
			System.out.println(Math.min(a*b,Math.min( b*c, c*a)));
		}

	}
	}