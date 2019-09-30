import java.util.*;

public class BLarge {
	static final int SIZE = 1100000;
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		boolean[] primes = new boolean[SIZE];
		Arrays.fill(primes, true);
		primes[0] = primes[1] = false;
		for(int i = 2; i < SIZE; i++){
			if(primes[i]){
				for(int j = 2 * i; j < SIZE; j += i){
					primes[j] = false;
				}
			}
		}
		
		int C = sc.nextInt();
		for(int caseID = 1; caseID <= C; caseID++){
			// these must be long for the LARGE INPUT
			long A = sc.nextLong();
			long B = sc.nextLong();
			long P = sc.nextLong();
			int cnt;
			if(P > B - A){
				cnt = (int)(B - A + 1);
			}
			else{
				int M = (int)(B - A);
				UFSet set = new UFSet(M + 1);
				for(int p = (int)P; p <= M; p++){
					if(primes[p]){
						int offset = (p - (int)(A % p)) % p;
						for(int x = offset; x + p <= M; x += p){
							set.merge(set.find(x), set.find(x + p));
						}
					}
				}
				cnt = 0;
				for(int i = 0; i <= M; i++){
					if(set.prev[i] == i) cnt++;
				}
			}
			System.out.printf("Case #%d: %d%n", caseID, cnt);
		}
	}
}

class UFSet {
	int n;
	int[] rank; // size of set i
	int[] prev; // parent of element i

	UFSet(int n) {
		this.n = n;
		rank = new int[n];
		Arrays.fill(rank, 1);
		prev = new int[n];
		for (int i = 0; i < n; i++)
			prev[i] = i;
	}

	int find(int x) {
		if (x != prev[x])
			prev[x] = find(prev[x]);
		return prev[x];
	}

	void merge(int a, int b) {
		if (rank[a] > rank[b])
			prev[b] = a;
		else {
			prev[a] = b;
			if (rank[a] == rank[b])
				rank[b]++;
		}
	}
}
