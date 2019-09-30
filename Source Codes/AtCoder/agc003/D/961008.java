import java.util.*;

public class Main {
	static class Factor {
		ArrayList<Long> f = new ArrayList<>();
		ArrayList<Integer> p = new ArrayList<>();
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] s = new long[N];
		for(int i=0; i<N; i++)
			s[i] = sc.nextLong();
		
		long[] norm = s.clone();
		HashMap<Long, Integer> cnt = new HashMap<>();
		HashMap<Long, Factor> map = new HashMap<>();
		for(int i=0; i<N; i++) {
			Factor fac = new Factor();
			long div = s[i];
			for(long j=2; j*j*j<=div; j++) {
				int k=0;
				while(div%j==0) {
					div /= j;
					k++;
					if(k%3==0)
						norm[i] /= j*j*j;
				}
				if(k%3>0) {
					fac.f.add(j);
					fac.p.add(k%3);
				}
			}
			long sqrt = (long)Math.floor(Math.sqrt(div+0.5));
			if(sqrt*sqrt==div && sqrt>1) {
				fac.f.add(sqrt);
				fac.p.add(2);
			} else {
				fac.f.add(div);
				fac.p.add(1);
			}
			if(!cnt.containsKey(norm[i])) {
				cnt.put(norm[i], 1);
				map.put(norm[i], fac);
			} else {
				cnt.put(norm[i], cnt.get(norm[i])+1);
			}
		}
		
		int ans = 0;
		
		for(Long key : cnt.keySet()) {
			if(key==1) {
				ans++;
			} else {
				int normCnt = cnt.get(key);
				long pair = 1;
				Factor cur = map.get(key);
				for(int i=0; i<cur.f.size(); i++) {
					for(int j=0; j<3-cur.p.get(i); j++) {
						double check = (double)pair*cur.f.get(i);
						if(check>10000000000l)
							pair = 0;
						else
							pair *= cur.f.get(i);
					}
				}
				int pairCnt = cnt.containsKey(pair) ? cnt.get(pair) : 0;
				if(normCnt > pairCnt || (normCnt==pairCnt && key>pair))
					ans += normCnt;
			}
		}
		
		System.out.println(ans);
		sc.close();
	}
}