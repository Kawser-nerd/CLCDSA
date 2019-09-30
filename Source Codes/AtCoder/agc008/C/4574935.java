import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		long I=sc.nextLong();
		long O=sc.nextLong();
		long T=sc.nextLong();
		long J=sc.nextLong();
		long L=sc.nextLong();
		long S=sc.nextLong();
		long Z=sc.nextLong();
		long ans=0;
		long tmp=0;
		if(I>0) {
			ans+=((I-1)/2)*2;
			//pl("I"+((I-1)/2)*2);
		}
		ans+=O;
		if(J>0) {
			ans+=((J-1)/2)*2;
			//pl("J"+((J-1)/2)*2);
		}
		if(L>0) {
			ans+=((L-1)/2)*2;
			//pl("L"+((L-1)/2)*2);
		}
		if(I>0 && J>0 && L>0) {
			ans+=3;
		}

		tmp+=I/2*2;
		tmp+=O;
		tmp+=J/2*2;
		tmp+=L/2*2;
		pl(Math.max(ans,tmp));
		//??????????????????????????????????
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
}