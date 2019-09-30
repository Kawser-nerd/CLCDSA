import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double a = sc.nextInt();
		double b = sc.nextInt();
		if(a*b%2!=0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}