import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		int R=sc.nextInt();
		int G=sc.nextInt();
		int B=sc.nextInt();
		//???
		long max=Integer.MAX_VALUE;
		//??????????????
		for(int i=-300; i<=300; i++) {
			int g=0;
			int gleft=0-i;
			int gright=G-i-1;
			if(gleft>=0 && gright>=0) {
				g+=G*(G-1)/2+gleft*G;
			}
			else if(gright>=0 && gleft<=0) {
				g+=gright*(gright+1)/2+(-gleft)*(-gleft+1)/2;
			}
			else if(gleft<=0 && gright<=0) {
				g+=G*(G-1)/2+(-gright)*G;
			}
			//pl("g"+g);
			long r=Integer.MAX_VALUE;
			for(int j=gleft-1; j>=gleft-601; j--) {
				long rright=j;
				long rleft=j+1-R;
				long rtmp=0;
				if(rright>-100) {
					rtmp+=(rright+100)*(rright+101)/2;
					if(rleft>-100) {
						rtmp-=(rleft+99)*(rleft+100)/2;
					}
					else if(rleft<=-100) {
						rtmp+=(-100-rleft)*(-99-rleft)/2;
					}
				}
				else if(rright<=-100) {
					rtmp+=R*(-100-rright)+(R-1)*R/2;
				}
				r=Math.min(r, rtmp);
			}
			//pl("r"+r);
			long b=Integer.MAX_VALUE;
			for(int j=gright+1; j<=gright+601; j++) {
				long bleft=j;
				long bright=j-1+B;
				long btmp=0;
				if(bleft<100) {
					btmp+=(101-bleft)*(100-bleft)/2;
					if(bright<100) {
						btmp-=(100-bright)*(99-bright)/2;
					}
					else if(bright>=100) {
						btmp+=(bright-100)*(bright-99)/2;
					}
				}
				else if(bleft>=100) {
					btmp+=B*(bleft-100)+(B-1)*B/2;
				}
				b=Math.min(b, btmp);
			}
			//pl("b"+b);
			//pl("r "+r+" g"+g+" b"+b+" sum"+(r+g+b));
			max=Math.min(max, r+g+b);
		}
		pl(max);
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
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
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