import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main (String [] args){

//		int x1 = Integer.parseInt(sc.next());
		BigDecimal x1 = new BigDecimal(Integer.parseInt(sc.next()));
		BigDecimal y1 = new BigDecimal(Integer.parseInt(sc.next()));
		BigDecimal x2 = new BigDecimal(Integer.parseInt(sc.next()));
		BigDecimal y2 = new BigDecimal(Integer.parseInt(sc.next()));
		BigDecimal x3 = new BigDecimal(Integer.parseInt(sc.next()));
		BigDecimal y3 = new BigDecimal(Integer.parseInt(sc.next()));
		double c = 0;
		BigDecimal bd = new BigDecimal(c);
		BigDecimal two = new BigDecimal(2.0);
		bd = x1.multiply(y2).add(x2.multiply(y3)).add(x3.multiply(y1)).subtract(y1.multiply(x2)).subtract(y2.multiply(x3)).subtract(y3.multiply(x1)).divide(two);
		bd.setScale(3, BigDecimal.ROUND_HALF_UP);
		System.out.println(bd.abs());
		System.out.flush();
		sc.close();
	}
}