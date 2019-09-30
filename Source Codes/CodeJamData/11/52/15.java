import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz = 1; zz <= T; zz++){
			int N = in.nextInt();
			int[] MC = new int[10000];
			for(int i = 0; i < N; i++){
				MC[in.nextInt()-1]++;
			}
			int ans = 0;
			int[] C = new int[10000];
			int[] E = new int[10000];
			for(int i = 1; i <= N; i++){
				boolean good = true;
				for(int j = 0; j < 10000; j++)
					C[j] = MC[j];
				Arrays.fill(E, 0);
				for(int j = 0; j < 10000; j++){
					while(C[j] > 0){
						boolean legal = true;
						if(j+i > 10000){
							legal = false;
						}else{
							for(int k = 0; k < i; k++)
								if(C[j+k] == 0)
									legal = false;
						}
						if(legal){
							for(int k = 0; k < i; k++)
								C[j+k]--;
							if(j+i < 10000)
								E[j+i]++;
						}else{
							if(E[j] > 0){
								E[j]--;
								C[j]--;
								if(j+1 < 10000)
									E[j+1]++;
							}else{
								good = false;
								break;
							}
						}
					}
				}
				if(good){
					ans = i;
				}
			}
			System.out.format("Case #%d: %d\n", zz, ans);
		}
	}
}
