import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		int Alice = sc.nextInt();
		int Borys = sc.nextInt();

		int dif = Borys - Alice;

		if(dif %2 == 0) {
			System.out.println("Alice");
		} else {
			System.out.println("Borys");
		}
	}	
}