import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;

public class A {
	static int[] bases;
	static HashSet<Integer> loop;
	
	public static boolean isHappy (int x, int b) {
		loop = new HashSet<Integer>();
		return dfs(x, b);
	}
	
	public static boolean dfs (int x, int b) {
		if (x == 1)
			return true;
		if (loop.contains(x))
			return false;
		
		loop.add(x);
		int y = 0;
		for (int i = x; i > 0; i /= b)
			y += (i % b) * (i % b);
		return dfs(y, b);
	}
	
	//11814485
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		PrintStream ps = new PrintStream(new FileOutputStream("A-large.out"));
		
		int cases = Integer.parseInt(br.readLine());
		
		HashMap<String,Integer> mem = new HashMap<String,Integer>();
		mem.put("5 6 7 8 9 10", 11814485);
		mem.put("2 5 6 7 8 9 10", 11814485);
		mem.put("3 5 6 7 8 9 10", 11814485);
		mem.put("4 5 6 7 8 9 10", 11814485);
		mem.put("2 3 5 6 7 8 9 10", 11814485);
		mem.put("2 4 5 6 7 8 9 10", 11814485);
		mem.put("3 4 5 6 7 8 9 10", 11814485);
		mem.put("2 3 4 5 6 7 8 9 10", 11814485);
		
		for (int itr = 1; itr <= cases; itr++) {
			String in = br.readLine().trim();
			int out = 1;
			if (mem.containsKey(in))
				out = mem.get(in);
			else {
				String[] sp = in.split(" ");
				bases = new int [sp.length];
				for (int i = 0; i < bases.length; i++)
					bases[i] = Integer.parseInt(sp[i]);
				
				boolean valid = false;
				while (!valid) {
					out++;
					valid = true;
					for (int i = 0; i < bases.length; i++)
						if (!isHappy(out, bases[i])) {
							valid = false;
							break;
						}
					if (out % 1000000 == 0)
						System.out.println(out);
	//				System.out.println(out + " " + cnt);
				}
				mem.put(in, out);
			}
			
			ps.println("Case #" + itr + ": " + out);
			System.out.println("Case #" + itr + ": " + out);
		}
		
		br.close();
		ps.close();
	}

}
