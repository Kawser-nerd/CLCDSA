import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		
		while (n != 0) {
			int amari = n%-2<0? 1 : n%2;
			sb.append(amari);
			n -= amari;
			n /= -2;
		}
		
		sb.reverse();
		System.out.println(sb.toString().equals("")? 0 : sb);
		
	}
}