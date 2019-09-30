import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		String s=sc.next();
		String[] wake=s.split("/");
		int[] ymd=new int[3];
		for(int i=0; i<3; i++) {
			ymd[i]=Integer.parseInt(wake[i]);
		}
		if((ymd[0]%ymd[1])==0 && (ymd[0]/ymd[1])%ymd[2]==0) {
			pl(s);
			System.exit(0);
		}
		else {
			int y=ymd[0]*520+ymd[1]*40+ymd[2];
			ymd[1]=1;
			ymd[2]=1;
			for(int i=ymd[0]; i<=7440; i++) {
				for(int j=ymd[1]; j<=12; j++) {
					for(int k=ymd[2]; k<=day(i,j); k++) {
						if(i%(j*k)==0) {
							if(y<=i*520+j*40+k) {
								pf(i,j,k);
								System.exit(0);
							}
						}
					}
				}
			}
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
	public static boolean isUru(int year) {
		if(year%4==0) {
			if(year%100==0 && year%400!=0) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			return false;
		}
	}
	public static int day(int year,int month) {
		int[] normal= {0,31,28,31,30,31,30,31,31,30,31,30,31};
		int[] uru= {0,31,29,31,30,31,30,31,31,30,31,30,31};
		if(isUru(year)) {
			return uru[month];
		}
		else {
			return normal[month];
		}
	}
	public static void pf(int year,int month,int day) {
		if(month<10) {
			if(day<10) {
				pl(year+"/0"+month+"/0"+day);
				return;
			}
			else {
				pl(year+"/0"+month+"/"+day);
				return;
			}
		}
		else if(month>=10) {
			if(day<10) {
				pl(year+"/"+month+"/0"+day);
				return;
			}
			else {
				pl(year+"/"+month+"/"+day);
				return;
			}
		}
		//pl(year+" "+month+" "+day);
	}
}