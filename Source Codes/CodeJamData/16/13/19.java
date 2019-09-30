import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
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
	
	private Object solve() throws Exception {
		int n = ni();
		int[] bff = nia(n);
		for(int i =0; i< bff.length;i ++){
			bff[i]--;
		}
		
		List<Chain> completes = new ArrayList<>();
		List<Chain> incompletes = new ArrayList<>();
		
		for(int i =0;i<n;i++){
			Chain chain = buildChain(i, bff);
			if(chain != null){
				if(chain.complete){
					completes.add(chain);
				} else {
					incompletes.add(chain);
				}
			}
		}
		
		incompletes = retainMaximals(incompletes, n);
		
		int best = calc_incompletes(incompletes, n);
		for(Chain c : completes)
			best = Math.max(best,c.set.size());
		
		return best;
	}
	
	private int calc_incompletes(List<Chain> incompletes, int n) {
		int[] count = new int[n];
		for(Chain c : incompletes){
			int a = c.list.get(c.list.size()-1);
			int b = c.list.get(c.list.size()-2);
			
			count[a]++;
			count[b]++;
		}
		
		int total =0;
		for(int c : count)
			if(c==2)
				total++;
		
		int sum = 0;
		for(Chain c : incompletes)
			sum += c.list.size();
		return sum - total;
	}

	private List<Chain> retainMaximals(List<Chain> incompletes, int n) {
		List<Chain> list = new ArrayList<>();
		boolean[] keep = new boolean[n];
		for(int i =0; i < n;i++){
			int biggest = 0;
			int index = -1;
			
			for(int j =0; j< incompletes.size();j++){
				Chain c = incompletes.get(j);
				if(c.set.contains(i) && c.set.size() > biggest){
					biggest = c.set.size();
					index = j;
				}
			}
			if(index != -1){
				keep[index] = true;
			}
		}
		for(int i =0;i < incompletes.size();i++)
			if(keep[i])
				list.add(incompletes.get(i));
		
		List<Chain> ret = new ArrayList<>();
		for(int i =0;i<n;i++){
			List<Chain> aux = new ArrayList<>();
			for(Chain c : list)
				if(c.list.get(c.list.size()-1) == i)
					aux.add(c);
			if(!aux.isEmpty()){
				Chain c = aux.get(0);
				for(int j =1;j<aux.size();j++) {
					Chain c2 = aux.get(j);
					if(c2.list.size() > c.list.size())
						c = c2;
				}
				ret.add(c);
			}
					
		}
		return ret;
	}

	private Chain buildChain(int start, int[] bff) {
		int n = bff.length;
		boolean[] seen = new boolean[n];
		List<Integer> list = new ArrayList<>();
		
		list.add(start);
		seen[start] = true;
		
		int curr = start;
		while(!seen[bff[curr]]) {
			curr = bff[curr];
			seen[curr]=true;
			list.add(curr);
		}
		
		if(bff[curr] != list.get(0) && bff[curr] != list.get(list.size()-2))
			return null;
		
		return new Chain(list, list.size() > 2 && bff[curr] == list.get(0));
	}
	
	class Chain{
		List<Integer> list;
		boolean complete;
		Set<Integer> set;
		
		public Chain(List<Integer> list, boolean complete) {
			this.list = list;
			this.complete = complete;
			this.set = new HashSet<>(list);
		}
		
		
	}
	// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	public static BufferedReader in;
	public static PrintWriter out;
	static String name_class = "C"; //
	static String loc = "/home/miguel/workspace/CodeJam/1A2016/src"; //

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