import java.io.*;
import java.util.*;

public class Template {
	public static void main(String[] args) throws IOException {
		if(!testing) pw = new PrintWriter(new FileWriter("out.txt"));
		int numTests = Integer.parseInt(rd.readLine());
		int[] X = new int[200], Y = new int[200];
		int c = 0;
		for(int i=0; i<14; i++) for(int j=0; j<14; j++) {
			X[c] = i;
			Y[c] = j;
			c++;
		}
		for(int t=1; t<=numTests; t++){
			st = new StringTokenizer(rd.readLine());
			int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
			pw.print("Case #"+t+": ");
			int sum = Math.abs(x) + Math.abs(y);
			int n = binary(1, 10000, sum);
			int sn = (n*n+n)>>1;
			if((sn-sum)%2!=0){
				n++;
				sn += n;
			}
			if((sn-sum)%2!=0){
				n++;
				sn += n+1;
			}
			int subtr = (sn-sum)/2;
			int an = -1;
			if(subtr>n){
				an = subtr-n;
				subtr = n;
			}
			char[] res = new char[n+1];
			boolean[] marked = new boolean[n+1];
			int left = Math.abs(x);
			ArrayList<Integer> first = new ArrayList<Integer>();
			ArrayList<Integer> second = new ArrayList<Integer>();
				for(int i=n; i>=1; i--){
					if(subtr==i || an==i) continue;
					if(i<=left){
						left -= i;
						marked[i] = true;
						first.add(i);
					}
					else{
						second.add(i);
					}
				}
				for(int i=0; i<first.size(); i++){
					int cur = first.get(i);
					res[cur] = (x>0? 'E': 'W');
				}
				for(int i=0; i<second.size(); i++){
					int cur = second.get(i);
					res[cur] = (y>0? 'N': 'S');
				}
				res[subtr] = (y>0? 'S': 'N');
				if(an!=-1) res[an] = (y>0? 'S': 'N');
				
			if(!simulate(x, y, res)){
				marked = new boolean[n+1];
				left = Math.abs(y);
				first = new ArrayList<Integer>();
				second = new ArrayList<Integer>();
					for(int i=n; i>=1; i--){
						if(subtr==i || i==an) continue;
						if(i<=left){
							left -= i;
							marked[i] = true;
							second.add(i);
						}
						else{
							first.add(i);
						}
					}
					for(int i=0; i<first.size(); i++){
						int cur = first.get(i);
						res[cur] = (x>0? 'E': 'W');
					}
					for(int i=0; i<second.size(); i++){
						int cur = second.get(i);
						res[cur] = (y>0? 'N': 'S');
					}
					res[subtr] = (x>0? 'W': 'E');
					if(an!=-1) res[an] = (x>0? 'W': 'E');
			}
			if(!simulate(x, y, res)){
				System.exit(1);
			}
			for(int i=1; i<=n; i++) pw.print(res[i]);
			pw.println();
		}
		pw.flush();
	}
	
	
	static boolean simulate(int x, int y, char[] res){
		int curX = 0, curY = 0;
		for(int i=1; i<res.length; i++){
			char ch = res[i];
			if(ch=='E'){
				curX += i;
			}
			else if(ch=='W'){
				curX -= i;
			}
			else if(ch=='N'){
				curY += i;
			}
			else{
				curY -= i;
			}
		}
		return curX==x && curY==y;
	}
	
	static int binary(int l, int r, int n){
		if(l==r) return r;
		if(r==l+1) return ok(l, n)? l: r;
		int m = (l+r)>>1;
		return ok(m, n)? binary(l, m, n): binary(m+1, r, n);
	}
	
	
	static boolean ok(int x, int n){
		return x*x+x>=2*n;
	}
	
	static StringTokenizer st;
	static BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	
	static boolean testing = false;
	
}
