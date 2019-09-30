import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

class Equation {
	int modulo = 10009;
	
	int[][] lexs;
	
	int[][] sts = new int[1001][6];
	
	public Equation(String s) {
		String[] tmp = s.split("[+]");
		
 		lexs = new int[tmp.length][26];
 		for (int i = 0; i < lexs.length; i++) 
 			for (int j = 0; j < tmp[i].length(); j++) lexs[i][tmp[i].charAt(j)-'a']++;
	}
	
	public int power(int v, int s) {
		if (v == 0) return 0;
		if (s == 0) return 1;
		
		if (sts[v][s] != 0) return sts[v][s];
		
		sts[v][s] = (power(v, s-1)*v) % modulo;
		
		return sts[v][s];
	}
	
	public int calc(int[] current) {
		int ans = 0;
		for (int i = 0; i < lexs.length; i++) {
			int ans2 = 1;
			for (int j = 0; j < 26; j++) {
				if (lexs[i][j] != 0)
					ans2 = ans2*power(current[j], lexs[i][j])%modulo;
			}
			ans += ans2;
		}
		return ans%modulo;
	}
}

public class A {
	int modulo = 10009;
	int[] current;
	
	Equation eq;
	
	int n,k;
	
	int[][] words;
	
	public int cnk(int n, int k) {
		BigInteger ans = BigInteger.ONE;
		for (int i = k+1; i <= n; i++) ans = ans.multiply(BigInteger.valueOf(i));
		for (int i = 1; i <= n-k; i++) ans = ans.divide(BigInteger.valueOf(i));
		
		return (int) (ans.longValue()%modulo);
	}
	
	public int rec(int ost, int num) {
		if (ost == 0) {
			return eq.calc(current);
		}
		
		if (num == n) return 0;
		
		int ans = 0;
		
		for (int i = 0; i <= ost; i++) {
			// izmenit' current
			for (int j = 0; j < 26; j++)
				current[j] += i*words[num][j];
			
			ans = (ans+rec(ost-i, num+1)*cnk(ost,i))%modulo;
			
			for (int j = 0; j < 26; j++)
				current[j] -= i*words[num][j];
		}
		
		return ans;
	}
	
	public void run() throws FileNotFoundException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintWriter output = new PrintWriter(new File("output.txt"));
		
		int t = input.nextInt();
		input.nextLine();

		for (int tt = 0; tt < t; tt++) {
			System.out.println(tt);
			
			String tmp = input.nextLine();
			k = Integer.parseInt(tmp.split(" ")[1]);
			tmp = tmp.split(" ")[0];
			
			eq = new Equation(tmp);
			
			n = input.nextInt();
			input.nextLine();
			
			words = new int[n][26];
			
			for (int i = 0; i < n; i++) {
				String word = input.nextLine();
				for (int j = 0; j < word.length(); j++) words[i][word.charAt(j)-'a']++;
			}
			
			output.print("Case #" + (tt + 1) + ": "); //+ans!
			for (int i = 1; i <= k; i++) {
				current = new int[26];
				
				output.print(rec(i,0));
				if (i != k) output.print(" ");
			}
				
			output.println();
		}

		input.close();
		output.close();
	}

	public static void main(String[] args) throws FileNotFoundException {
		(new A()).run();
	}
}