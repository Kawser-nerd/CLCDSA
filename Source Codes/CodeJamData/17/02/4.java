import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.lang.*;
public class B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for (int x = 0; x < n; x++) {
			BigInteger tmp2 = input.nextBigInteger();
			char[] tmpArr = tmp2.toString().toCharArray();
			String tmp = tmp2.toString();
			lbl: while (true) {
				int prev = 0;
				for (int a = 0; a < tmp.length(); a++) {
//					System.out.println(tmp2 + " " + a + " " + ((int) tmpArr[a]) + " " + prev);
					if (tmpArr[a] < prev) {
						for (int b = a; b < tmp.length(); b++) {
							tmpArr[b] = '0';
						}
						String xD = new String(tmpArr);
						tmp2 = new BigInteger(xD);
						tmp2 = tmp2.subtract(BigInteger.ONE);
						tmp = tmp2.toString();
						tmpArr = tmp.toCharArray();
						continue lbl;
					} else {
						prev = tmpArr[a];
					}
				}
				break;
			}

			System.out.println("Case #" + (x + 1) + ": " + tmp2);
		}
	}

	
}
