import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Rotate {
	public static void main(String args[]) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
		int N,K, cases;
		cases = Integer.parseInt(in.readLine());
		double gold = (1+Math.sqrt(5))/2;
		for(int i=1; i<=cases; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			N = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			char board[][] = new char[N][N];
			for(int r=0; r<N; r++) {
				String s = in.readLine();
				String t = "";
				for(int c=0; c<N; c++) if(s.charAt(c)!='.') t+=s.charAt(c);
				while(t.length()<N) t = "."+t;
				for(int c=0; c<N; c++) 
					board[r][c] = t.charAt(c);
			}
			
			boolean red = false;
			boolean blue = false;
			
			char last = '.';
			int streak = 0;
			for(int r=0; r<N; r++){
				last = '.';
				streak = 0;
				for(int c=0; c<N; c++) {
					if(board[r][c]=='.'||board[r][c]!=last) {
						streak = 1;
						last = board[r][c];
					}
					else {
						streak++;
						if(streak==K) {
							if(last=='R') red = true;
							if(last=='B') blue = true;
						}
					}
				}
			}
			
			for(int c=0; c<N; c++){
				last = '.';
				streak = 0;
				for(int r=0; r<N; r++) {
					if(board[r][c]=='.'||board[r][c]!=last) {
						streak = 1;
						last = board[r][c];
					}
					else {
						streak++;
						if(streak==K) {
							if(last=='R') red = true;
							if(last=='B') blue = true;
						}
					}
				}
			}
			
			for(int sum=0; sum<2*N-1; sum++){
				last = '.';
				streak = 0;
				for(int r=0; r<N; r++) {
					if(sum-r<0||sum-r>=N) continue;
					if(board[r][sum-r]=='.'||board[r][sum-r]!=last) {
						streak = 1;
						last = board[r][sum-r];
					}
					else {
						streak++;
						if(streak==K) {
							if(last=='R') red = true;
							if(last=='B') blue = true;
						}
					}
				}
			}
			
			for(int diff=1-N; diff<N-1; diff++){
				last = '.';
				streak = 0;
				for(int r=0; r<N; r++) {
					if(diff+r<0||diff+r>=N) continue;
					if(board[r][diff+r]=='.'||board[r][diff+r]!=last) {
						streak = 1;
						last = board[r][diff+r];
					}
					else {
						streak++;
						if(streak==K) {
							if(last=='R') red = true;
							if(last=='B') blue = true;
						}
					}
				}
			}
				
			out.println("Case #"+i+": "+(red?(blue?"Both":"Red"):(blue?"Blue":"Neither")));
		}
			
		out.close();
	}
}
