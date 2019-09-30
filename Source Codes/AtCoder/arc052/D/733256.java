import java.util.HashMap;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		long k = in.nextLong();
		long m = in.nextLong();
		long half = m / 100000;
		HashMap<Long, Long> hp = new HashMap<>();
		for (int i = 0; i < 100000; i++){
			long diff = (i - sum(i) + k) % k;
			if (hp.containsKey(diff)){
				hp.put(diff, hp.get(diff) + 1);
			} else {
				hp.put(diff, (long)1);
			}
		}
		long re = 0;
		for (long i = 0; i < half; i++){
			long diff = (i * 100000 - sum(i) + k) % k;
			if (hp.containsKey((k-diff)%k)) {
				re += hp.get((k-diff)%k);
			}
		}
		for (long i = half * 100000; i <= m; i++){
			if (sum(i) % k == i % k){
				re++;
			}
		}
		in.close();
		StringBuilder sb = new StringBuilder();
		sb.append(re - 1);
		System.out.println(sb.toString());
	}
	
	public static int sum(long a){
		int result = 0;
		while (a > 0) {
			result += a % 10;
			a = a/10;
		}
		return result;
	}

}