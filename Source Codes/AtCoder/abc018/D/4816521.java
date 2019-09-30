import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		int P=sc.nextInt();
		int Q=sc.nextInt();
		int R=sc.nextInt();
		int max=0;
		int[][] matrix=new int[N+1][M+1];
		int[] man=new int[M+1];
		int[] select=new int[N+1];
		for(int i=0; i<=N; i++) {
			for(int j=0; j<=M; j++) {
				matrix[i][j]=0;
			}
		}
		man[0]=0;
		for(int i=0; i<R; i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			int z=sc.nextInt();
			matrix[x][y]=z;
		}

		int tansaku=1;
		for(int i=0; i<N; i++) {
			tansaku*=2;
		}
		for(int i=0; i<tansaku; i++) {
			int pp=pop(i);	//????????
			if(pp<=P) {
				int tmp=i;
				for(int j=1; j<=N; j++) {
					select[j]=tmp%2;
					tmp/=2;
				}
				for(int j=1; j<=M; j++) {
					man[j]=0;
					for(int k=1; k<=N; k++) {
						man[j]+=select[k]*matrix[k][j];
					}
				}
				Arrays.sort(man);
				tmp=0;
				for(int j=0; j<Q; j++) {
					tmp+=man[M-j];
				}
				max=Math.max(max, tmp);
			}
		}
		pl(max);
	}
	static int pop(int a) {
		int counter=0;
		while(a>0) {
			counter+=a%2;
			a/=2;
		}
		return counter;
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