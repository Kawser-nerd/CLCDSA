import java.util.*;

// Do not use int, use long!!

public class Main {
	public static void main(String args[]){
			Scanner sc = new Scanner(System.in);
			
			int n = sc.nextInt();
			int q = sc.nextInt();
			int[] ar = new int[n];
			for (int i = 0; i < q; i++) {
				int tmpl = sc.nextInt();
				int tmpr = sc.nextInt();
				int tmp = sc.nextInt();
				for (int j = tmpl-1; j < tmpr; j++) {
					ar[j] = tmp;
				}
			}

			for (int i = 0; i < n; i++) {
				System.out.println(ar[i]);
			}

			sc.close();
		}

}