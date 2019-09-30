import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt(), B = sc.nextInt();
		int D[] = {A+B, A-B, A*B};
		Arrays.sort(D);
		System.out.println(D[2]);
		sc.close();
	}

}