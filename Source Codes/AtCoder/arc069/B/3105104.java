import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String goal = br.readLine();
		generate("SS", goal);
		generate("WS", goal);
		generate("SW", goal);
		generate("WW", goal);
		System.out.println(-1);
	}
	
	public static void generate(String prefix, String goal) {
		char[] ret = new char[goal.length()];
		ret[0] = prefix.charAt(0);
		ret[1] = prefix.charAt(1);
		for(int i = 2; i < ret.length; i++) {
			if(ret[i-1] == 'S') {
				if(goal.charAt(i-1) == 'o') {
					ret[i] = ret[i-2];
				}
				else {
					ret[i] = (char)('S' + (int)'W' - ret[i-2]);
				}
			}
			else {
				if(goal.charAt(i-1) == 'x') {
					ret[i] = ret[i-2];
				}
				else {
					ret[i] = (char)('S' + (int)'W' - ret[i-2]);
				}
			}
		}
		if(isConsistent(ret, goal)) {
			System.out.println(new String(ret));
			System.exit(0);
		}
	}
	
	public static boolean isConsistent(char[] l, String s) {
		for(int i = 0; i < l.length; i++) {
			int lhs = (i+l.length-1)%l.length;
			int rhs = (i+1)%l.length;
			if(l[i] == 'S') {
				if(s.charAt(i) == 'o' && l[lhs] != l[rhs]) return false;
				if(s.charAt(i) == 'x' && l[lhs] == l[rhs]) return false;
			}
			else {
				if(s.charAt(i) == 'o' && l[lhs] == l[rhs]) return false;
				if(s.charAt(i) == 'x' && l[lhs] != l[rhs]) return false;
			}
		}
		return true;
	}
	
}