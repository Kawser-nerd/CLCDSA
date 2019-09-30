package qualification;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws IOException {
		String file = "B-large";
		Scanner sc = new Scanner(new FileReader(file + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(file + ".out"));

		int cases = sc.nextInt(); sc.nextLine();
		for(int cas = 1; cas <= cases; cas++) {
			int n = sc.nextInt();
			BigInteger[] arr = new BigInteger[n]; 
			for(int i = 0; i < n; i++)
				arr[i] = sc.nextBigInteger();
			Arrays.sort(arr);
			BigInteger max = BigInteger.ZERO;
			for(int i = 1; i < n; i++)
				max = max.gcd(arr[i].subtract(arr[i-1]));
			BigInteger ans = max.subtract(arr[0].mod(max)).mod(max);
			
			out.printf("Case #%d: %s%n", cas, ans.toString());
		}
		
		out.close();
	}
}
