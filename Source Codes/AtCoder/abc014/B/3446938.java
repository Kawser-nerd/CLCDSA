import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int X = sc.nextInt();
		int[] a = new int[n];
		for(int i = 0;i < n;++i)
			a[i] = sc.nextInt();
		sc.close();
		
		boolean[] bin = new boolean[n];
		for(int i = 0;i < n;++i) {
			if((X % (int)Math.pow(2, i+1)) / (int)Math.pow(2, i) == 1)
				bin[i] = true;
			else
				bin[i] = false;
		}
		
		int ans = 0;
		for(int i = 0;i < n;++i)
			if(bin[i])
				ans += a[i];
		
		System.out.println(ans);
	}
}