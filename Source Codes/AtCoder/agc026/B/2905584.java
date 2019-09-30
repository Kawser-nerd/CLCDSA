import java.util.*;

public class Main {
	static long gcd(long a,long b) {
		if(b == 0)return a;
		return gcd(b,a % b);
	}
	static boolean check(long a,long b,long c,long d) {
		if(a < b || d < b)return false;
		if(c + 1 >= b)return true;
		///??????  ?????c(??????  ?????b ???????? 
		///?????c < a - bx + dy < b??????No 
		///???a - b < bx - dy < a - c
		///?????????? ???(a-b,a-c)?????gcd(b,d)??? ?????
		long g = gcd(b,d);
		return (a - c - 1) / g - (a - b) / g <= 0;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i = 0;i < t;i ++) {
			long a = in.nextLong();
			long b = in.nextLong();
			long c = in.nextLong();
			long d = in.nextLong();
			if(check(a,b,c,d))System.out.println("Yes");
			else System.out.println("No");
		}
	}

}