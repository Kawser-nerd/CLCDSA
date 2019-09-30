import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Random;
import java.util.Scanner;


public class ProperShuffle {
	static final String fileName = "C-small-attempt0";
	
	class Pair implements Comparable<Pair>{
		int count;
		String val;
		Pair(String v, int c){
			count = c;
			val =v;
		}
		@Override
		public int compareTo(Pair p) {
			return Integer.compare(count, p.count);
		}
		@Override
		public String toString() {
			return val + " " + count;
		}
	}
	ProperShuffle(){
		Scanner in = new Scanner(System.in);
		
		/*String start = "01234567";
		count = new HashMap<>();
		search(start, 0);
		
		int total = 0;
		ArrayList<Pair> pairs = new ArrayList<>();
		for(Entry<String, Integer> e: count.entrySet())
			pairs.add(new Pair(e.getKey(), e.getValue()));
		Collections.sort(pairs);
		for(Pair p: pairs)
			System.out.println(p);*/
		
		/*int tests = 1000;
		System.out.println(tests);
		for(int t = 0; t<tests/2; t++){
			int n = 1000;
			System.out.println(n);
			int[] ary = new int[n];
			for(int i = 0; i<n; i++)
				ary[i] = i;
			good(ary);
			System.out.println(Arrays.toString(ary).replaceAll("[^ 0-9]", ""));
			
			System.out.println(n);
			for(int i = 0; i<n; i++)
				ary[i] = i;
			bad(ary);
			System.out.println(Arrays.toString(ary).replaceAll("[^ 0-9]", ""));
		}*/
		
		
		/*int tests = in.nextInt();
		int countBad = 0;
		int countGood = 0;
		double tol = 486;
		for(int t = 1; t<=tests; t++){
			int n = in.nextInt();
			int[] ary = new int[n];
			for(int i = 0; i<n; i++)
				ary[i] = in.nextInt();
			double dif = 0;
			for(int i = 0; i<ary.length; i++)
				dif += ary[i] < i ? 1:0;
			//dif /= n;
			if((t&1)==0){ // bad
				if(dif < tol)
					countBad++;
			}else{ // good
				if(dif < tol)
					countGood++;
			}
			System.out.println(t+": "+((t&1)==0 ? "BAD ":"GOOD ")+dif);
		}
		System.err.println("bads below: "+countBad);
		System.err.println("goods below: "+countGood);
		System.err.println("wrongs: "+(500-countBad+countGood));
		System.err.println("percentCorrect: "+(1000f-(500-countBad+countGood))/1000f);*/
		
		
		int tests = in.nextInt();
		double tol = 486;
		for(int t = 1; t<=tests; t++){
			int n = in.nextInt();
			int[] ary = new int[n];
			for(int i = 0; i<n; i++)
				ary[i] = in.nextInt();
			double dif = 0;
			for(int i = 0; i<ary.length; i++)
				dif += ary[i] < i ? 1:0;
			System.out.printf("Case #%d: %s\n", t, dif < tol ? "BAD" : "GOOD");
		}
		in.close();
	}
	double sq(double v){
		return v*v;
	}
	Random rand = new Random();
	void bad(int[] ary){
		for(int i = 0; i<ary.length; i++){
			int p = rand.nextInt(ary.length);
			swap(ary, i, p);
		}
	}
	void good(int[] ary){
		for(int i = 0; i<ary.length; i++){
			int p = rand.nextInt(ary.length-i)+i;
			swap(ary, i, p);
		}
	}
	void swap(int[] ary, int i, int j){
		int tmp = ary[i];
		ary[i] = ary[j];
		ary[j] = tmp;
	}
	int longestIncrSub(int[] ary){
		int[] q = new int[ary.length];
		int max;
		for(int k = 0; k<ary.length; k++){
			max = 0;
			for(int j = 0; j<k; j++)
				if(q[j] > max && ary[k] > ary[j]) max = q[j];
			q[k] = max+1;
		}
		max = 0;
		for(int i = 0; i<ary.length; i++)
			if(q[i] > max) max = q[i];
		return max;
	}
	HashMap<String, Integer> count;
	void search(String v, int i){
		if(i == v.length()){
			if(!count.containsKey(v))
				count.put(v, 1);
			else count.put(v, count.get(v)+1);
			return;
		}
		for(int x = 0; x<v.length(); x++)
			search(swap(v, i, x), i+1);
	}
	String swap(String s, int i, int k){
		StringBuilder build = new StringBuilder();
		for(int x = 0; x<s.length(); x++)
			if(x == i)
				build.append(s.charAt(k));
			else if(x == k)
				build.append(s.charAt(i));
			else build.append(s.charAt(x));
		return build.toString();
	}
	
	public static void main(String[] args) throws Exception{
		String root = "C:/Users/Tyler/Downloads/";
		String file = ProperShuffle.fileName;
		System.setIn(new FileInputStream(new File(root+file+".in")));
		System.setOut(new PrintStream(new File(root+file+".out")));
		new ProperShuffle();
	}
}
