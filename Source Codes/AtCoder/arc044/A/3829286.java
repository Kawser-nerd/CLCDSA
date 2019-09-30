import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();

		if(!isPrime(N) && ((N%3==0 || N%5==0) || (N!=2 && N%2==0)) || N==1) {
			System.out.println("Not Prime");
		}
		else {
			System.out.println("Prime");
		}
	}
	public static boolean isPrime(int a) {
		if(a<4) {
			if(a==2 || a==3) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			for(int j=2; j<=root(a); j++) {
				if(a%j==0) {
					return false;
				}
				if(a%j!=0 && (j+1)*(j+1)>a) {
					return true;
				}
		}
		return true;
		}
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
	static int root(int a) {
		int ketasu=0;
		int tmp=a;
		while(tmp>0) {
			ketasu++;
			tmp/=10;
		}
		int constant=(ketasu+1)/2;	//?????????
		if(ketasu>=1) {
			int[] suuji=new int[constant];
			tmp=a;
			for(int i=0; i<constant; i++) {
				suuji[constant-1-i]=a%100;
				a/=100;
			}
			int ans=0;
			int kai=0;
			int mae=0;
			if(constant<=1) {
				for(int i=10; i>=0; i--) {
					if(suuji[0]>=i*i) {
						return i;
					}
				}
			}
			else {
				for(int i=0; i<constant; i++) {
					mae+=kai*2;
					for(int j=9; j>=0; j--) {
						if((mae*10+j)*j<=suuji[i]) {
							ans=ans*10+j;
							mae*=10;
							kai=j;
							if(i+1<constant) {
								suuji[i+1]+=(suuji[i]-(mae+j)*j)*100;
							}
							break;
						}
					}
				}
			}
			return ans;
		}
		else {
			return 0;
		}
	}
}