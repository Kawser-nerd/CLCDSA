import java.util.*;

public class Main {
	static class RangeMinimumQuery {
		int N;
		long[] v;
		
		public RangeMinimumQuery(int n) {
			N=1;
			while(N<n)
				N<<=1;
			v = new long[N<<1];
		}
		
		public void add(int i, long x) {
			i+=N;
			while(i>0) {
				v[i] += x;
				i >>=1;
			}
		}
		
		//minimum value in range [a, b)
		public long getSum(int a, int b) {
			return getSum(a, b, 1, 0, N);
		}
		
		public long getSum(int a, int b, int k, int l, int r) {
			if(a<=l && r<=b)
				return v[k];
			else if(r<=a || b<=l)
				return 0;
			else
				return getSum(a, b, k*2, l, (l+r)/2) + getSum(a, b, k*2+1, (l+r)/2, r);
		}
		public long get(int i) {
			return v[i+N];
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		char[] s = sc.next().toCharArray();
		int N = s.length;

		ArrayList<ArrayList<Integer>> index = new ArrayList<>();
		for(int i=0; i<26; i++)
			index.add(new ArrayList<>());
		
		for(int i=0; i<N; i++)
			index.get(s[i]-'a').add(i);
		
		int oddNum=0;
		for(int i=0; i<26; i++)
			if(index.get(i).size()%2==1)
				oddNum++;
		if(oddNum>1) {
			System.out.println(-1);
		} else {
			long ans = 0;
			boolean[] used = new boolean[N];
			int[] cnt = new int[26];
			RangeMinimumQuery rmq = new RangeMinimumQuery(N);
			
			for(int i=0; i<N; i++) {
				if(!used[i]) {
					int c = s[i]-'a';
					int pair = index.get(c).get(index.get(c).size() - cnt[c] - 1);
					if(i==pair)
						ans += (N - i -1 -rmq.getSum(i+1, N))/2;
					else
						ans += (N -pair -1 -rmq.getSum(pair+1, N));
					used[pair]=true;
					rmq.add(pair, 1);
					cnt[c]++;
				}
			}
			
			System.out.println(ans);
		}
		sc.close();
	}
	
}