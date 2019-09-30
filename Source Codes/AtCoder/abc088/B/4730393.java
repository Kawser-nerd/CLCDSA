import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.nextLine();
		Integer[]a = new Integer[N];
		int ans = 0;
		int Alice = 0;
		int Bob = 0;
		
		for(int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();
		
		Arrays.sort(a, Comparator.reverseOrder());
		
		for(int i = 0; i < N; i++) {
			if( i % 2 == 0 ) {
				Alice += a[i];
			}else {
				Bob += a[i];
			}
		}
		System.out.println(Alice - Bob);
	}
}