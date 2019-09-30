import java.util.*;

public class Main {
	static class Num {
		int a;
		double log;
		int cnt;
		public Num(int a, double log) {
			this.a = a;
			this.log = log;
		}
		
	}
	static final long MOD = 1000000007;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		Num[] num = new Num[N];
		for(int i=0; i<N; i++) {
			int a = sc.nextInt();
			num[i] = new Num(a, Math.log(a));
		}
		
		if(A==1) {
			Arrays.sort(num, new Comparator<Num>() {
				public int compare(Num n1, Num n2) {
					return n1.a-n2.a;
				}
			});
			
			for(int i=0; i<N; i++)
				System.out.println(num[i].a);
			sc.close();
			return;
		}
		
		final double add = Math.log(A);
		
		double min = 0.0;
		double max = 1e11;
		for(int i=0; i<80; i++) {
			double mid = (min+max)/2;
			long sum = 0;
			for(int j=0; j<N; j++) {
				if(num[j].log<mid)
					sum += (mid-num[j].log)/add;
			}
			
			if(sum>=B)
				max = mid;
			else
				min = mid;
		}
		
		int sum = 0;
		for(int i=0; i<N; i++) {
			if(num[i].log<min)
				num[i].cnt = (int)((min-num[i].log)/add);
			sum += num[i].cnt;
		}
		
		while(sum<B) {
			int idx = 0;
			for(int i=1; i<N; i++)
				if(num[i].log+add*num[i].cnt<num[idx].log+add*num[idx].cnt)
					idx = i;
			num[idx].cnt++;
			sum++;
		}
		
		Arrays.sort(num, new Comparator<Num>() {
			public int compare(Num n1, Num n2) {
				return Double.compare(n1.log+add*n1.cnt, n2.log+add*n2.cnt);
			}
		});
		
		for(int i=0; i<N; i++)
			System.out.println((num[i].a*pow(A, num[i].cnt))%MOD);
		
		sc.close();
	}

	static long pow(long a, int b) {
		long ans = 1;
		while(b>0) {
			if((b&1)!=0)
				ans = (ans * a)%MOD;
			a = (a * a)%MOD;
			b>>=1;
		}
		
		return ans;
	}
}