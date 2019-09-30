import java.lang.*;
import java.math.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int len = s.length();

		BigDecimal val = new BigDecimal("0." + s);
		BigDecimal ten = BigDecimal.TEN;
		BigDecimal wg = BigDecimal.ONE;
		for(int i = 0; i < len; ++i){
			wg = wg.divide(ten);
		}

		for(int dot = 1; dot <= len; ++dot){
			val = val.multiply(ten);
			wg = wg.multiply(ten);
			BigDecimal a = val.multiply(val).setScale(0, BigDecimal.ROUND_CEILING);
			BigDecimal b = val.add(wg);
			BigDecimal c = b.multiply(b);
			if(a.compareTo(c) < 0){
				System.out.println(a);
				return;
			}
		}
	}
}