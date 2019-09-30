import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		if(N % 111 == 0) {
			System.out.println(N);
		}
		else {
			int a = N / 111 + 1;
			System.out.println(a * 100 + a * 10 + a);
		}
	}

}