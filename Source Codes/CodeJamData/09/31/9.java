import java.io.*;
import java.math.*;

	public class a {
		public static void main(String [] args)
		{
			BufferedReader input = new BufferedReader (new InputStreamReader (System.in));
			try {
				int cases = Integer.valueOf(input.readLine());
				for (int cas = 1; cas <= cases; cas++) {
					String line = input.readLine();
					int digit[] = new int[256];
					int base = 0, i;
					BigInteger num = new BigInteger("0");
					for (i = 0; i < 256; i++) digit[i] = -1;
					for (i = 0; i < line.length(); i++) {
						if ((line.charAt(i) < '0' || line.charAt(i) > '9') && (line.charAt(i) < 'a' || line.charAt(i) > 'z')) continue;
						if (digit[line.charAt(i)] == -1) {
							if (base == 0) digit[line.charAt(i)] = 1;
							else if (base == 1) digit[line.charAt(i)] = 0;
							else digit[line.charAt(i)] = base;
							base++;
						}
					}
					if (base < 2) base = 2;
					int cnt = 0;
					for (i = 0; i < line.length(); i++) {
						if ((line.charAt(i) < '0' || line.charAt(i) > '9') && (line.charAt(i) < 'a' || line.charAt(i) > 'z')) continue;
						num = num.multiply(BigInteger.valueOf(base));
						num = num.add(BigInteger.valueOf(digit[line.charAt(i)]));
					}
					System.out.printf("Case #%d: ", cas);
					System.out.println(num);
				}
			} catch (java.io.IOException e) {
			}
		}
	};
