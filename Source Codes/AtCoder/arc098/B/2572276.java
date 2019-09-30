import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int N = sc.nextInt();
		int[] vals = new int[N];
		for (int i = 0; i < vals.length; i++) {
			vals[i] = sc.nextInt();
		}
		long ans = 0, xor = 0, acum = 0, lastOk = 0;
		for (int i = 0; i < N; i++) {
			xor ^= vals[i];
			acum += vals[i];
			while (xor != acum) {
				xor ^= vals[(int)lastOk];
				acum -= vals[(int)lastOk];
				lastOk++;
			}
			ans += i - lastOk + 1;
		}
		System.out.println(ans);
	}
}