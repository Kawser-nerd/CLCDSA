import java.util.*;
import java.math.*;

public class Main {

	public static void main(String[] args) {

		int total = 0;
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String C = sc.next();

		for (int i=0; i<C.length(); i++) {
			char ca = C.charAt(i);
			if (ca=='A') {total += 4;}
			else if (ca=='B') {total += 3;}
			else if (ca=='C') {total += 2;}
			else if (ca=='D') {total += 1;}
		}

		BigDecimal divided = new BigDecimal(total);
		BigDecimal divisor = new BigDecimal(N);
		BigDecimal ans = divided.divide(divisor,10,RoundingMode.HALF_UP);
		System.out.println(ans);

		sc.close();

	}

}