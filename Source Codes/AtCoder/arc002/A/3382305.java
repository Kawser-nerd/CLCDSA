import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int Y = sc.nextInt();
		sc.close();
		if (Y % 400 == 0) System.out.println("YES");
		else if (Y % 100 == 0) System.out.println("NO");
		else if (Y % 4 == 0) System.out.println("YES");
		else System.out.println("NO");
	}
}