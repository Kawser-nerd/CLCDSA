import java.util.*;
import java.io.*;

public class Solution {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int T = sc.nextInt();
		
		for (int caseNum=1; caseNum <= T; caseNum++) {
			int R = sc.nextInt(), C = sc.nextInt();
			char[][] data = new char[R][C];
			for (int i=0; i<R; i++) {
				data[i] = sc.next().toCharArray();
			}
			boolean ok = true;
			for (int i=0; i<R && ok; i++)
				for (int j=0; j<C && ok; j++)
					if (data[i][j] == '#') {
						if (i+1<R && j+1<C && data[i+1][j] == '#' && data[i][j+1] == '#' && data[i+1][j+1] == '#') {
							data[i][j] = data[i+1][j+1] = '/';
							data[i+1][j] = data[i][j+1] = '\\';
						} else ok = false;
					}
			pw.println("Case #" + caseNum + ":");
			if (ok) {
				for (int i=0; i < R; i++) pw.println(new String(data[i]));
			} else pw.println("Impossible");
		}
		
		sc.close();
		pw.flush();
		pw.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}
