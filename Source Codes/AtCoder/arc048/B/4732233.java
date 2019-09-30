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
		int[][] te=new int[1_000_001][3];
		int[] bunpu=new int[1000002];
		for(int i=0; i<1000000; i++) {
			Arrays.fill(te[i],0);
		}
		Arrays.fill(bunpu,0);
		int[][] ary=new int[N][2];
		for(int i=0; i<N; i++) {
			ary[i][0]=sc.nextInt();
			ary[i][1]=sc.nextInt()-1;
			te[ary[i][0]][ary[i][1]]++;
			bunpu[ary[i][0]+1]++;
		}
		for(int i=1; i<=1000001; i++) {
			bunpu[i]=bunpu[i]+bunpu[i-1];
		}
		for(int i=0; i<N; i++) {
			int w=bunpu[ary[i][0]];	//????????????
			int l=0;
			int d=0;
			if(ary[i][1]==0) {	//gu-
				w+=te[ary[i][0]][1];	//????????
				if(te[ary[i][0]][0]>0) {
					d+=te[ary[i][0]][0]-1;	//???????
				}
				l=N-w-d-1;
			}
			else if(ary[i][1]==1) {	//???
				w+=te[ary[i][0]][2];	//pa-?????
				if(te[ary[i][0]][1]>0) {
					d+=te[ary[i][0]][1]-1;	//cyoki??????
				}
				l=N-w-d-1;
			}
			else if(ary[i][1]==2) {	//pa-
				w+=te[ary[i][0]][0];	//gu-?????
				if(te[ary[i][0]][2]>0) {
					d+=te[ary[i][0]][2]-1;	//???????
				}
				l=N-w-d-1;
			}
			pl(w+" "+l+" "+d);
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