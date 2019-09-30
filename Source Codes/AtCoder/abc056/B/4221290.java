import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in) ;

	int w = sc.nextInt();
	int a = sc.nextInt();
	int b = sc.nextInt();

	System.out.println(a + w < b ? b - a - w : b + w < a ? a - b - w : 0);

	sc.close();
	}

}