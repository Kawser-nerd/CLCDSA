import java.math.BigInteger;
import java.util.*;

public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cas=1; cas<=T; cas++) {
			int n = in.nextInt();
			List<List<Integer>> E = new ArrayList<List<Integer>>();
			for(int i=0; i<n; i++) E.add(new ArrayList<Integer>()); //(i,j) means X[i]>X[j]
			int[] D = new int[n];
			
			int[] A = new int[n];
			int[] B = new int[n];
			for(int i=0; i<n; i++)
				A[i] = in.nextInt();
			for(int i=0; i<n; i++)
				B[i] = in.nextInt();
			
			for(int i=0; i<n; i++) {
				for(int j=i-1; j>=0; j--)
					if(A[i]==A[j]+1) {
						E.get(i).add(j);
						D[j]++;
						break;
					}
				for(int j=0; j<i; j++)
					if(A[i]==A[j]) {
						E.get(j).add(i);
						D[i]++;
					}
			}
			//System.out.println(Arrays.toString(D));
			for(int i=n-1; i>=0; i--) {
				for(int j=i+1; j<n; j++)
					if(B[i]==B[j]+1) {
						E.get(i).add(j);
						D[j]++;
						break;
					}
				for(int j=i+1; j<n; j++)
					if(B[i]==B[j]) {
						E.get(j).add(i);
						D[i]++;
					}
			}
			//System.out.println(Arrays.toString(D));
			
			
			int[] X = new int[n];
			boolean[] U = new boolean[n];
			VAL: for(int val=n; val>=1; val--) {
				//System.out.println(Arrays.toString(D));
				for(int t=n-1; t>=0; t--) {
					if(D[t]==0 && !U[t]) {
						X[t] = val;
						U[t] = true;
						for(Integer y : E.get(t))
							D[y]--;
						continue VAL;
					}
				}
			}
			System.out.printf("Case #%d:", cas);
			for(int i=0; i<n; i++)
				System.out.printf(" %d", X[i]);
			System.out.println();
		}
	}
}
