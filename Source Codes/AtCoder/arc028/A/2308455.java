import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		n = n % (a + b);
		if (n <= a && n != 0)
			System.out.println("Ant");
		else
			System.out.println("Bug");
	}
}