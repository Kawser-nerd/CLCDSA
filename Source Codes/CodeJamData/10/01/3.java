import java.io.*;
import java.util.*;

public class Solution {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int T = sc.nextInt();
		for (int t=0; t < T; t++) {
			int N = sc.nextInt(), K = sc.nextInt();
			int mask = (1<<N) - 1;
			pw.print("Case #" + (t+1) + ": ");
			pw.println((K & mask) == mask ? "ON" : "OFF");
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}
