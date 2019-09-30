import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int D = B / A;
		if (D < C)
			System.out.println(D);
		else
			System.out.println(C);
	}

}