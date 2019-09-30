import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();
		int n = sc.nextInt();
		System.out.println((int) (Math.pow(100,d)) * (n + n / 100) );
	}

}