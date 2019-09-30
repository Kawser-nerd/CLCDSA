import java.io.*;
import java.util.*;

public class Template {
	public static void main(String[] args) throws IOException {
		if(!testing) pw = new PrintWriter(new FileWriter("out.txt"));
		rd = new BufferedReader(new FileReader("A-large(2).txt"));
		int numTests = Integer.parseInt(rd.readLine());
		for(int x=1; x<=numTests; x++){
			intervals.clear();
			st = new StringTokenizer(rd.readLine());
			S = st.nextToken();
			n  = Integer.parseInt(st.nextToken());
			boolean still = true;
			int start = -1;
			for(int i=0; i<S.length(); i++){
				char ch = S.charAt(i);
				if(isVowel(ch)){
					if(!still || start==-1){
						start = i;
						still = true;
					}
					continue;
				}
				else{
					if(still && start!=-1){
						if(i-start>=n)
							intervals.add(new Interval(start, i-1));
	//					System.out.println("added "+start+" "+(i-1));
					}
					still = false;
				}
			}
			if(isVowel(S.charAt(S.length()-1))){
				if(S.length()-start>=n) intervals.add(new Interval(start, S.length()-1));
	//			System.out.println("added "+start+" "+(S.length()-1));
			}
			Collections.sort(intervals, Interval.cmp);
			int curInt = 0;
			long ans = 0;
			for(int i=0; i<S.length(); i++){
				if(curInt==intervals.size()) break;
				int till = intervals.get(curInt).x+n-1;
		//		System.out.println(i+" "+end);
				ans += (S.length()-till);
				if(intervals.get(curInt).x==i){
					intervals.get(curInt).x++;
					if(intervals.get(curInt).y-intervals.get(curInt).x+1<n) curInt++;
				}
			}
			pw.println("Case #"+x+": "+ans);
		}
		pw.flush();
	}
	
	static ArrayList<Interval> intervals = new ArrayList<Interval>();
	
	static boolean isVowel(char ch){
		return !(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
	}
	
	static String S;
	
	static int n;
	
	static StringTokenizer st;
	static BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	
	static boolean testing = false;
	
}

class Interval{
	public int x, y;
	
	public Interval(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	public static Comparator<Interval> cmp = new Comparator<Interval>() {
		
		@Override
		public int compare(Interval o1, Interval o2) {
			return o1.x-o2.x;
		}
	};
	
}