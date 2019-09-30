import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		long M = scanner.nextLong();
		long[] A = new long[N+1];
		long[] sum = new long[N+1];
		for(int i = 1; i <= N; i++){
			A[i] = scanner.nextLong();
		}
		sum[0] = 0;
		for(int i = 1; i <= N; i++){
			sum[i] = sum[i-1] + A[i];
		}
		TreeMap<Long,Long> map = new TreeMap<Long,Long>();
		for(int i = 0; i <= N; i++){
			long key = sum[i] % M;
			if(map.containsKey(key)){
				map.put(key, map.get(key)+1);
			}else{
				map.put(key, 1L);
			}
		}
		long ans = 0;
		for(long value : map.values()){
			if(value > 1){
				ans += value * (value-1) / 2;
			}
		}
		System.out.println(ans);
	}
}