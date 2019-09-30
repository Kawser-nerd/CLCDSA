import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	char[] cs;
	
	void read() {
		cs = sc.next().toCharArray();
	}
	
	String[] S = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	
	int[] id = {
			0, 'z', 2, 'w', 6, 'x', 8, 'g', 7, 's', 5, 'v', 4, 'f', 3, 't', 1, 'o', 9, 'i'
	};
	
	void solve() {
		int[] count = new int[256];
		for (int i = 0; i < cs.length; i++) count[cs[i]]++;
		int[] res = new int[10];
		for (int i = 0; i < 10; i++) {
			char c = Character.toUpperCase((char)id[i * 2 + 1]);
			int num = (count[c]);
			res[id[i * 2]] = num;
			for (char d : S[id[i * 2]].toCharArray()) count[d] -= num;
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < res[i]; j++) System.out.print(i);
		}
		System.out.println();
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (A.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new A().run();
	}
}
