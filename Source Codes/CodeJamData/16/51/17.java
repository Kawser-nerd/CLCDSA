//done

package cj2016.r3;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc;
	PrintWriter pw;
	char[] c;
	
	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"A-large";

		try {
			new A().run(filePrefix);
		} catch(Exception e) {
			System.err.println(e);
		}
	}
	
	public void run(String filePrefix) throws Exception {
		sc = new Scanner(new FileReader(filePrefix + ".in"));
		pw = new PrintWriter(new FileWriter(filePrefix + ".out"));
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			read(sc);
			pw.print("Case #" + test + ": ");
			System.out.print("Case #" + test + ": ");
			solve();
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
		
	}
	
	void read(Scanner sc) {
		c = sc.next().toCharArray();
	}
	
	void print(Object s) {
		pw.print(s);
		System.out.print(s);
	}
	
	void println(Object s) {
		pw.println(s);
		System.out.println(s);
	}
	
	void solve() {
		int N = c.length;
		int score = 0;
		
		LinkedList<Character> stack = new LinkedList<Character>();
		for(int i=0; i<N; i++) {
			if(!stack.isEmpty() && stack.peek()==c[i]) {
				stack.pop();
				score += 10;
			} else {
				stack.push(c[i]);
			}
		}
		
		println(score+stack.size()/2*5);
	}
}
