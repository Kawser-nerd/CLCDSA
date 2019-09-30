import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/C-large.in"))));

		String output = "";
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= t; i++) {
			int n = sc.nextInt();
			int j = sc.nextInt();
			
			long num = (1l<<(n-1))+1;
			int count = 0;
			
			output += "Case #" + i + ":\n";
			
			while (count < j) {
				String s = Long.toBinaryString(num);
				boolean found = true;
				ArrayList<Integer> factors = new ArrayList<Integer>();
				for (int k = 2; k <= 10; k++) {
					BigInteger big = new BigInteger(s, k);
					if (big.isProbablePrime(10)) {
						found = false;
						break;
					}
					int factor = -1;
					for (int m = 3; m < 1000; m += 2) {
						if (big.mod(new BigInteger(""+m)).equals(BigInteger.ZERO)) {
							factor = m;
							break;
						}
					}
					if (factor == -1) {
						found = false;
						break;
					}
					factors.add(factor);
				}
				if (found) {
					count++;
					output += s;
					for (int k : factors) {
						output += " "+k;
					}
					output += "\n";
				}
				
				num += 2;
			}
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/C-large.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}