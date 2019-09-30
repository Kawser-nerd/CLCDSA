import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		/*
		 * ?????????????????
		 * ?????X?Y??????????????
		 * ???????????????????
		 *
		 */
		long MAX_S=6_000_000_000_000_000_000L;
		int N=sc.nextInt();
		int K=sc.nextInt();
		long MIN_S=6_000_000_000_000_000_000L;
		long[][] coordx=new long[N][2];
		long[][] coordy=new long[N][2];
		for(int i=0; i<N; i++) {
			long xx=sc.nextLong();
			long yy=sc.nextLong();
			coordx[i][0]=xx;
			coordx[i][1]=yy;
			coordy[i][0]=yy;
			coordy[i][1]=xx;
		}
		quick_sort(coordx,0,N-1);
		quick_sort(coordy,0,N-1);
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(i>=j) {
					for(int k=0; k<N; k++) {
						for(int l=0; l<N; l++) {
							if(k>=l) {
								long minx=coordx[j][0];
								long maxx=coordx[i][0];
								long miny=coordy[l][0];
								long maxy=coordy[k][0];
								int num=0;
								for(int m=0; m<N; m++) {
									if(minx<=coordx[m][0] && coordx[m][0]<=maxx) {
										if(miny<=coordx[m][1] && coordx[m][1]<=maxy) {
											num++;
										}
									}
								}
								if(num>=K) {
									MIN_S=Math.min(MIN_S, (maxx-minx)*(maxy-miny));
								}
							}
						}
					}
				}
			}
		}
		pl(MIN_S);
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
	static void quick_sort(long[][] d, int left, int right) {
		if (left>=right) {
			return;
		}
		long p = d[(left+right)/2][0];
		int l = left, r = right;
		long tmp,tmp1,tmp2;
		while(l<=r) {
			while(d[l][0] < p) { l++; }
			while(d[r][0] > p) { r--; }
			if (l<=r) {
				tmp = d[l][0]; d[l][0] = d[r][0]; d[r][0] = tmp;
				tmp1=d[l][1]; tmp2=d[r][1]; d[l][1]=tmp2; d[r][1]=tmp1;
				l++; r--;
			}
		}
		quick_sort(d, left, r);
		quick_sort(d, l, right);
	}
}