import java.util.*;
import static java.lang.Math.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		List<Long> aList = new ArrayList<>();
		for(int i=0; i<N; i++){
			aList.add(sc.nextLong());
		}

		sc.close();
		System.out.println(gcd(aList));

	}

	public static long gcd(long a, long b){

		// a>b???
		if(a<b){
			a = a^b;
			b = a^b;
			a = a^b;
		}

		long r = -1;
		while (r!=0){
			r = a%b;
			a = b;
			b = r;
		}

		return a;
	}

	public static long gcd(List<Long> aList) {

		final long len = aList.size();
		long gcd = gcd(aList.get(0), aList.get(1));
		for(int i = 2; i<len; i++){
			gcd = gcd(gcd, aList.get(i));
		}
		return gcd;
	}
}