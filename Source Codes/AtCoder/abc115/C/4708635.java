import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int n = sc.nextInt();
		int k = sc.nextInt();
		
		int[] h = new int[n];
		
		for(int i=0;i<n;i++) {
			h[i] = sc.nextInt();
		}
		
		//????????
		Arrays.sort(h);
		
		//k?????????????
		// ??n????d????? n-(k-1)???
		/*
		 * n=5, k=3
		 * 0 1 2 3 4 
		 * <--->
		 *   <--->
		 *     <--->
		 */
		int[] d = new int[n-(k-1)];
		
		for(int i=0;i<n-(k-1);i++) {
			d[i] = h[i+(k-1)] - h[i];
		}
		/*
		 * ?????????????????min????????
		 * ?????? O(NlogN) ??????????????????
		 */
		
		//??????????
		Arrays.sort(d); 
		
		out.println(d[0]);
		
		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}