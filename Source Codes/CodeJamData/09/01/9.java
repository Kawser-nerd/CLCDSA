package gcj2009.qual;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	static final int INF = 1 << 20;

	static char[][] css;

	public void run() {
		char[] key = sc.next().toCharArray();
		boolean[][] b = new boolean[L][127];
		for(int i = 0, j = 0; i < key.length; i++, j++)
			if(key[i] == '(')
				while(key[++i] != ')')
					b[j][key[i]] = true;
			else
				b[j][key[i]] = true;

		int ans = 0;
		loop : for(char[] cs : css) {
			for(int i = 0; i < L; i++) 
				if(!b[i][cs[i]])
					continue loop;
			ans++;
		}
		System.out.println(ans);
	}

	public static void main(String...args) {
		try { 
			System.setIn(new FileInputStream("A-large.in"));
			System.setOut(new PrintStream("A-large.out"));
		} catch(Exception e) {}
		sc = new Scanner(System.in);

		L = sc.nextInt();
		D = sc.nextInt();
		int N = sc.nextInt();
		css = new char[D][];
		for(int i = 0; i < D; i++)
			css[i] = sc.next().toCharArray();
		for(int n = 1; n <= N; n++) {
			System.out.printf("Case #%d: ", n);
			new A().run();
		}
	}

	static int L, D;
	static Scanner sc;
}
