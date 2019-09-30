import java.util.*;

public class Main {
	static final long MOD = 1000000007;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		HashMap<Long, Integer> num = new HashMap<>();
		int[][] c = new int[N][4];
		for(int i=0; i<N; i++) {
			for(int j=0; j<4; j++)
				c[i][j] = sc.nextInt();
			Long code = getCode(c[i]);
			if(num.containsKey(code))
				num.put(code, num.get(code)+1);
			else
				num.put(code, 1);
		}
		
		long ans = 0;
		int[][] side = new int[4][4];
		long[] sideCode = new long[4];

		for(int i=0; i<N; i++) {
			Long bottomCode = getCode(c[i]);
			num.put(bottomCode, num.get(bottomCode)-1);
			
			for(int j=0; j<4; j++) {
				side[j][0] = c[i][j];
				side[j][3] = c[i][(j+1)%4];
			}
			for(int j=i+1; j<N; j++) {
				long topCode = getCode(c[j]);
				for(int d=0; d<4; d++) {
					long temp = 1;
					for(int k=0; k<4; k++) {
						side[k][2] = c[j][(d-k+4)%4];
						side[k][1] = c[j][(d-k+5)%4];
						sideCode[k] = getCode(side[k]);

						Integer cnt = num.get(sideCode[k]);
						if(cnt!=null && cnt>0) {
							if(sideCode[k]==topCode && cnt>0)
								cnt--;
							
							for(int l=0; l<k; l++)
								if(sideCode[k]==sideCode[l] && cnt>0)
									cnt--;
							
							if(bit(sideCode[k], 0, 20)==bit(sideCode[k], 20, 40)) {
								cnt <<=1;
								if(bit(sideCode[k], 0, 10)==bit(sideCode[k], 10, 20))
									cnt <<=1;
							}
							temp *= cnt;
						} else {
							temp = 0;
							break;
						}
					}
					ans += temp;
				}
			}
		}
		
		System.out.println(ans);
		sc.close();
	}
	
	static long getCode(int[] c) {
		long code[] = new long[4];
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				code[i] = code[i]<<10 | c[(i+j)%4];
			}
		}
		Arrays.sort(code);
		return code[0];
	}
	
	static long bit(long v, int s, int t) {
		v >>= s;
		return v & ((1<<(t-s))-1);
	}
}