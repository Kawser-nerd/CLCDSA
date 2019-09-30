import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long s = sc.nextLong();

		System.out.println(ans(n,s));
	}

	static long ans(long n, long s) {
		if(n<s) {
			return -1;
		} else if (n==s) {
			return n+1;
		} else {
			List<Long> divisor = new ArrayList<Long>();

			for(long i=1;i<=Math.sqrt(n-s);i++) {
				if(digitSum(n,i+1)==s) {
					return i+1;
				}
				if((n-s)%i == 0) {
					divisor.add(i);
				}
			}
			Collections.reverse(divisor);
			for (Long l : divisor) {
				if(digitSum(n,(n-s)/l+1)==s) {
					return (n-s)/l+1;
				}
			}
			return -1;
		}
	}

	static long digitSum(long n, long b) {
		if(n < b) {
			return n;
		} else {
			return (n%b+digitSum(n/b, b));
		}
	}

}