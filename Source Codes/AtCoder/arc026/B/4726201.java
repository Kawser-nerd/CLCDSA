import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map.Entry;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		long N=sc.nextLong();
		List <Long> unko=new ArrayList<Long>();
		HashMap<Long,Long> yakusu=new HashMap<Long,Long>();
		fra(N,unko);
		for(int i=0; i<unko.size(); i++) {
			long num=unko.get(i);
			if(num==1) {
				//
			}
			else {
				if(yakusu.containsKey(num)) {
					yakusu.put(num,yakusu.get(num)+1);
				}
				else {
					yakusu.put(num,1L);
				}
			}
		}
		long sum=1;
		for(Entry<Long,Long> entry:yakusu.entrySet()) {
			long suji=entry.getKey();
			long kosu=entry.getValue();
			//pl(suji+" "+kosu);
			sum*=ketawa(suji,kosu);
		}
		sum-=N;
		if(sum==N) {
			pl("Perfect");
		}
		else if(sum<N) {
			pl("Deficient");
		}
		else if(sum>N) {
			pl("Abundant");
		}
		//pl(sum+" "+N);
	}
	public static long ketawa(long sj,long ks) {
		long aa=1;
		for(long i=0; i<=ks; i++) {
			aa*=sj;
		}
		return (aa-1)/(sj-1);
	}
	static class SC {
		private BufferedReader reader = null;
		private StringTokenizer tokenizer = null;
		public SC(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
		}
		public String next() {
			if (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new UncheckedIOException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
	public static void fra(long a,List<Long> p) {//long??
		for(long i=2; i*i<=a; i++) {
			if(a%i==0) {
				p.add(i);
				fra(a/i,p);
				return;
			}
		}
		p.add(a);
	}
}