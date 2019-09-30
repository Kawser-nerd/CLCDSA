import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String a = sc.next(), b = sc.next();
		int comp = new BigInteger(a).compareTo(new BigInteger(b));
		if (comp < 0) {
			System.out.println("LESS");
		} else if(comp == 0){
			System.out.println("EQUAL");
		} else{
			System.out.println("GREATER");
		}
	}
}