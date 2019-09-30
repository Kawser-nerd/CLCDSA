import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int n=s.nextInt(),k=s.nextInt(),t[]=new int[n+1];
		for(int i=0;i<n;i++)
			t[i+1]=s.nextInt();

		Arrays.parallelPrefix(t, Integer::sum);

		for(int i=3;i<=n;i++) {
			if(t[i]-t[i-3]<k) {
				System.out.println(i);
				return;
			}
		}
		System.out.println(-1);
	}
}