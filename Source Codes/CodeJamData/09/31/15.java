import java.util.Scanner;
import java.util.Arrays;
import java.math.BigInteger;

public class Base {

	public static char [] next;

	public static int [] map, inv;

	public static int count;

	public static BigInteger getNum () {
		
		BigInteger ret, bigCount;
		int d;
		
		bigCount = new BigInteger(""+count);
		ret = BigInteger.ZERO;
		for (char c : next) {
			d = (int) c;
			ret = ret.add(new BigInteger(""+map[d]));
			ret = ret.multiply(bigCount);
		}
		
		return ret.divide(bigCount);
		
	}

	public static void main (String [] args) {
		
		Scanner S;
		int T, d, caso;
		
		S = new Scanner (System.in);
		map = new int [128];
		inv = new int [128];
		T = S.nextInt();
		caso = 1;
		while (T-- > 0) {
			Arrays.fill(map, -1);
			Arrays.fill(inv, -1);
			next = S.next().toCharArray();
			count = 1;
			for (char c : next) {
				d = (int) c;
				if (map[d] == -1) {
					map[d] = count;
					inv[count] = d;
					count++;
					if (count==2)
						count = 0;
					if (count==1)
						count = 2;
				}
			}
			if (count==0)
				count = 2;
			System.out.println("Case #" + (caso++) + ": " + getNum());
		}
		
	}

}