import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int K = sc.nextInt();
		int a = 1,b = 1;
		for(int i=0; i<K; i++) {
			int temp = a+b;
			b = a;
			a = temp;
		}
		System.out.println(a + " " + b);

		sc.close();
	}
}