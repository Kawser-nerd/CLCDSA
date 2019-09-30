import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int [] m = new int [n];
		int min = 1000;
		int sum = 0;
		int a = 0;
		for(int i = 0; i < n; i++) {
			m[i] = sc.nextInt();
			if(m[i] < min) {
				min = m[i];
			}
			sum += m[i];
		}
		x = x - sum;
		a = x / min;
		System.out.println(a + n);
		sc.close();
	}

}