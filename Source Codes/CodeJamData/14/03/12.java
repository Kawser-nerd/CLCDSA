import java.util.*;
import java.io.*;

public class Minesweeper {
	static PrintWriter out;
	static{
		try {
			out = new PrintWriter(new File("c.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(System.in);
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int n = reader.nextInt();
			int m = reader.nextInt();
			int k = reader.nextInt();
			
			boolean trans = false;
			if(n < m){
				n ^= m;
				m ^= n;
				n ^= m;
				trans = true;
			}
			
			char[][] g = new char[n][m];
			for(char[] e:g)Arrays.fill(e,'.');
			
			int cnt = 0;
			for(int i = 0; i < n-2; i++)
				for(int j = 0; j < m-2 && cnt < k; j++, cnt++)
					g[i][j] = '*';
			g[n-1][m-1] = 'c';
			
			out.println("Case #"+t+":");
			if(cnt < k && m == 1){
				for(; cnt < k; cnt++)
					g[cnt][0] = '*';
				print(g,trans);
			}else if(cnt == k){
				print(g,trans);
			}else if(k == n*m-1){
				for(int i = 0; i < n; i++)
					for(int j = 0; j < m; j++)
						g[i][j] = '*';
				g[n-1][m-1] = 'c';
				print(g,trans);
			}else if((n*m - k > 1 && n*m - k < 4) || (n*m - k < 9 && (k-cnt)%2 == 1)){
				out.println("Impossible");
//				System.out.println(n + " " + m + " " + k);
			}else if((k-cnt)%2 == 1){ //Odd number
				if(n < 3 || m < 3){
					out.println("Impossible");
//					System.out.println(n + " " + m + " " + k);
					continue;
				}
				g[n-3][m-3] = '.';
				cnt--;
				for(int i = 0; i < n-3 && cnt < k; i++, cnt+=2){
					g[i][m-1] = '*';
					g[i][m-2] = '*';
				}
				for(int i = 0; i < m-3 && cnt < k; i++, cnt+=2){
					g[m-1][i] = '*';
					g[m-2][i] = '*';
				}
				
				if(cnt != k){
					out.println("Impossible");
//					System.out.println(n + " " + m + " " + k);
				}
				else
					print(g,trans);
			}else{
				for(int i = 0; i < n-2 && cnt < k; i++,cnt+=2){
					g[i][m-1] = '*';
					g[i][m-2] = '*';
				}
				for(int i = 0; i < m-2 && cnt < k; i++,cnt+=2){
					g[n-1][i] = '*';
					g[n-2][i] = '*';
				}
				if(cnt != k){
					out.println("Impossible");
//					System.out.println(n + " " + m + " " + k);
				}
				else
					print(g,trans);
			}
		}
		out.close();
	}
	
	public static void print(char[][] g, boolean transpose){
		if(transpose){
			for(int i = 0; i < g[0].length; i++){
				for(int j = 0; j < g.length; j++)
					out.print(g[j][i]);
				out.println();
			}
		}else{
			for(int i = 0; i < g.length; i++){
				for(int j = 0; j < g[0].length; j++)
					out.print(g[i][j]);
				out.println();
			}
		}
	}
}
