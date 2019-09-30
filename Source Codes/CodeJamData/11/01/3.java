import java.io.*;
import java.util.*;

public class A {
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	int N;
	int[] who, button;
	
	int solve()
	{
		int[] pos = new int[2], t = new int[2];
		pos[0] = pos[1] = 1;
		t[0] = t[1] = 0;
		int tot = 0;
		for(int i = 0; i < N; i++){
			t[who[i]] += Math.abs(button[i] - pos[who[i]]) + 1;
			if(i > 0){
				t[who[i]] = Math.max(t[who[i]], tot + 1);
			}
			tot = t[who[i]];
			pos[who[i]] = button[i];
		}
		return tot;
	}
	
	A() throws IOException {
		in = new BufferedReader(new FileReader("A.large.in"));
		out = new PrintWriter("A.large.out");
		eat("");
		
		int T = nextInt();
		for(int t = 1; t <= T; t++){
			N = nextInt();
			who = new int[N];
			button = new int[N];
			for(int i = 0; i < N; i++){
				if(next().equals("O")){
					who[i] = 0;
				}
				else{
					who[i] = 1;
				}
				button[i] = nextInt();
			}
			out.println("Case #" + t + ": " + solve());
		}
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws IOException {
		new A();
	}
}
