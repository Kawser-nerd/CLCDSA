import java.util.*;
import java.io.*;
/*
1
10
7 8 10 10 9 2 9 6 3 3
 */
public class C {
	static boolean[] been;
	static int[] goes;
	static int[] nums;
	static ArrayList<Integer>[] rev;
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		Scanner qwe = new Scanner(System.in);
		PrintWriter out = new PrintWriter("C.out");
		
		
		int T  = qwe.nextInt();
		
		for(int cse = 1; cse <= T; cse++){
			int N = qwe.nextInt();
			
			goes = new int[N];
			for (int i = 0; i < goes.length; i++) {
				goes[i] = qwe.nextInt()-1;
			}
			been = new boolean[N];
			nums = new int[N];
			
			int best = 0;
			for (int i = 0; i < N; i++) {
				best = Math.max(best, getaloop(i,1));
			}
			
			rev = new ArrayList[N];
			
			for (int i = 0; i < rev.length; i++) {
				rev[i] = new ArrayList<Integer>();
			}
			
			for (int i = 0; i < goes.length; i++) {
				rev[goes[i]].add(i);
			}
			been = new boolean[N];
			int cont = 0;
			for (int i = 0; i < goes.length; i++) {
				if(i == goes[goes[i]] && i < goes[i]){
					
					
					int o = goes[i];
					been[i] = true;
					been[o] = true;
					
					int bi = getapath(i);
					int bo = getapath(o);
					
					cont +=  bi+bo+2;
					been[i] = false;
					been[o] = false;
					
				}
			}
			best = Math.max(best, cont);
			
			out.println("Case #"+cse+": "+best);
			System.out.println("Case #"+cse+": "+best);
		}
		
		
		out.close();
		qwe.close();
	}
	
	public static int getaloop(int at, int num){
		
		if(been[at]) return 0;
		
		nums[at] = num;
		been[at] = true;
		
		int next = goes[at];
		int ret = 0;
		if(!been[next]){
			ret = getaloop(next,num+1);
		}
		else{
			if(nums[next] != 0) ret = num - nums[next]+1;
		}
		
		nums[at] = 0;
		return ret;
	}
	
	public static int getapath(int at){
		
		int best = 0;
		
		for(int to : rev[at]){
			if(!been[to]){
				been[to] = true;
				best = Math.max(best, 1+getapath(to));
				
				been[to] = false;
			}
		}
		
		//System.out.println("at " +  (at+1) + " best: " + best);
		
		return  best;
	}

}
