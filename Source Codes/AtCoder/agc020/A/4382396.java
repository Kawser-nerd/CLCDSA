import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {

			int n = sc.nextInt();
			System.out.println(Math.abs(sc.nextInt()-sc.nextInt())%2!=0? "Borys" : "Alice");

	}
}