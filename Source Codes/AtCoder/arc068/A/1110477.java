import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long n = in.nextLong();
		System.out.println((long)Math.ceil(n/11*2 + (n % 11 == 0 ? 0 : 1 + (n%11/7))));
	}
}