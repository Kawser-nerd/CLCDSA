import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

/**
 * http://abc030.contest.atcoder.jp/tasks/abc030_d
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		int a = sc.nextInt()-1;
		BigInteger k = new BigInteger(sc.next());
		int[] b = new int[N];
		for(int i=0; i<N; i++) b[i] = sc.nextInt()-1;
		sc.close();
		
		int count = 1;
		int current = b[a];
		int[] dpCount = new int[N];
		int[] dpPos = new int[N+1];
		while(dpCount[current]==0){
			dpCount[current] = count;
			dpPos[count] = current;
			current = b[current];
			count++;
		}
		
		int startRoop = dpCount[current];
		BigInteger rk = k.subtract(BigInteger.valueOf(startRoop));
		int ans = 0;
		if(rk.max(BigInteger.ZERO).equals(BigInteger.ZERO)){
			ans = dpPos[k.intValue()];
		}else{
			ans = dpPos[startRoop+rk.mod(BigInteger.valueOf(count-startRoop)).intValue()];
		}
		
		System.out.println(ans+1);
		
	}
	
}