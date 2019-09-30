import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class C {

	public static void main(String... args) throws Exception {
		configure();

		int casos = Integer.parseInt(in.readLine());
		for (int casito = 1; casito <= casos; casito++) {
			Object o = new C().solve();

			out.println("Case #" + casito + ": " + o);
			System.out.println("Case #" + casito + ": " + o);
		}
		out.close();
	}
	
	private Quat i = new Quat(1,1);
	private Quat j = new Quat(1,2);
	private Quat k = new Quat(1,3);
	

	private Object solve() throws Exception {
		int L = ni();
		long X = nl();
		String s = in.readLine();
		int[] arr = new int[L];
		for(int index =0;index<L;index++)
			arr[index] = s.charAt(index)-'i'+1;
		
		Quat[] prefix = prefix(arr);
		Quat[] suffix = suffix(arr);
		
		Quat acum = prefix[prefix.length-1];
		if(!check(acum,X%4L)){
			return "NO";
		}
		
		long first_i = computeFirstI(prefix);
		long last_k = computeLastK(suffix, X * ( (long) L ));

		return (first_i< last_k? "YES" : "NO");
	}
	
	private long computeLastK(Quat[] suffix, long length) {
		
		long n = suffix.length;
		Quat acum = suffix[0];
		
		long last_k = -1;
		
		for(long index =0;index<suffix.length;index++){
			long times =0;
			Quat check = suffix[(int) index]; 
			while(times < 4L){
				if( check.equals(k) ){
					long length_suffix = (times+1) *( (long) n) - ((long) index);
					last_k = Math.max(length - length_suffix , last_k);
					break;
				}else{
					check = check.multiply(acum);
				}
				times++;
			}
		}
		return last_k;
	}

	private long computeFirstI(Quat[] prefix) {
		long n = prefix.length;
		Quat acum = prefix[((int) n)-1];
		
		long first_i = Long.MAX_VALUE;
		
		for(long index =0;index<prefix.length;index++){
			long times =0;
			Quat check = prefix[(int)index]; 
			while(times < 4L){
				if( check.equals(i) ){
					first_i = Math.min(times * ( (long) n) + ((long) index), first_i);
					break;
				}else{
					check = acum.multiply(check);
				}
				times++;
			}
		}
		return first_i;
	}

	private boolean check(Quat quat, long l) {
		Quat check = new Quat(1,0);
		for(long index =0;index < l; index++)
			check = check.multiply(quat);
		
		return check.equals(i.multiply(j).multiply(k));
	}

	private Quat[] prefix(int[] arr) {
		int n = arr.length;
		Quat[] ret = new Quat[n];
		ret[0] = new Quat(1,arr[0]);
		for(int index = 1;index<n;index++){
			ret[index]= ret[index-1].multiply(new Quat(1,arr[index]));
		}
		return ret;
	}

	private Quat[] suffix(int[] arr) {
		int n = arr.length;
		Quat[] ret = new Quat[n];
		ret[n-1] = new Quat(1,arr[n-1]);
		for(int index = n-2;index>=0;index--){
			ret[index]= new Quat(1,arr[index]).multiply(ret[index+1]);
		}
		return ret;
	}
	
	static class Quat{
		static int[][][] multi = new int[][][]{ 
			{ {1,0}, {1,1}, {1,2}, {1,3} },
			{ {1,1}, {-1,0}, {1,3}, {-1,2} },
			{ {1,2}, {-1,3}, {-1,0}, {1,1} },
			{ {1,3}, {1,2}, {-1,1}, {-1,0} }
		};
		
		int sgn;
		int type;
		
		public Quat(int sgn, int type){
			this.sgn = sgn;
			this.type = type;
		}
		
		public Quat multiply(Quat q){
			int[] result = Quat.multi[this.type][q.type];
			int res_sgn = result[0] * this.sgn * q.sgn;
			return new Quat(res_sgn, result[1]);
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Quat other = (Quat) obj;
			if (sgn != other.sgn)
				return false;
			if (type != other.type)
				return false;
			return true;
		}

		@Override
		public String toString() {
			return ""+(sgn==-1? "-": "") + (char)(type==0? '1' : 'i'+(type-1));
		}
		
	}

	// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	public static BufferedReader in;
	public static PrintWriter out;
	static String name_class = "C"; //
	static String loc = "/home/miguel/workspace/CodeJam/qualy/src"; //

	static void configure() throws Exception {

		File file = new File(loc);
		File[] paths = file.listFiles();
		List<File> input = new ArrayList<File>();
		for (File f : paths) {
			String s = f.getName();
			if (s.startsWith(name_class) && s.endsWith(".in"))
				input.add(f);
		}

		if (input.isEmpty()) {
			System.err.println("LEYENDO DE CONSOLA");
			in = new BufferedReader(new InputStreamReader(System.in));
		} else {
			File last_file = input.get(0);
			for (File f : input) {
				if (f.lastModified() > last_file.lastModified())
					last_file = f;
			}

			in = new BufferedReader(new FileReader(last_file.toString()));
			System.err.println("LEYENDO DE ARCHIVO");

		}
		FileWriter fw = new FileWriter(loc + "/output.txt");
		out = new PrintWriter(fw);

	}

	static StringTokenizer strTok = new StringTokenizer("");

	static String nextToken() throws IOException {
		while (!strTok.hasMoreTokens())
			strTok = new StringTokenizer(in.readLine());
		return strTok.nextToken();
	}

	static int ni() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nl() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nd() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int[] nia(int size) throws IOException {
		int[] ret = new int[size];
		for (int i = 0; i < size; i++)
			ret[i] = ni();
		return ret;
	}

	static long[] nla(int size) throws IOException {
		long[] ret = new long[size];
		for (int i = 0; i < size; i++)
			ret[i] = nl();
		return ret;
	}

	static double[] nda(int size) throws IOException {
		double[] ret = new double[size];
		for (int i = 0; i < size; i++)
			ret[i] = nd();
		return ret;
	}

}