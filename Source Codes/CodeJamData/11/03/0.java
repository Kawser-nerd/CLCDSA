import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz = 1; zz <= T;zz++){
			int N = in.nextInt();
			int[] C = new int[N];
			for(int i = 0; i < N;i++)
				C[i] = in.nextInt();
			int test = 0;
			for(int c:C)
				test ^= c;
			if(test != 0){
				System.out.format("Case #%d: NO\n", zz);
			}else{
				long min = Long.MAX_VALUE;
				long sum = 0;
				for(int c:C){
					sum += c;
					min = min(min, c);
				}
				System.out.format("Case #%d: %d\n", zz, sum-min);
			}
			
		}
	}
}
