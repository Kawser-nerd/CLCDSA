import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Welcome {
	
	public static void main(String[] args) throws Exception {
		int i,j,k,p;
		char c;
		int res;
		String score;
		String line;
		String sentence;
		String original = "welcome to code jam";
		int N, M;
		
		BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C-large.out")));
		
		StringTokenizer st;
		line = br.readLine();
		N = Integer.parseInt(line);
		
		for (k=1;k<=N;k++) {
			sentence = br.readLine();
			M = sentence.length();
			
			int opt[][] = new int[M][19];
			
			for (i=0;i<M;i++) {
				c = sentence.charAt(i);
				
				if (c == 'w') {
					// we can start a word from here
					opt[i][0] = 1;
				}
				
				for (j=1;j<19;j++) {
					if (c == original.charAt(j)) {
						// we stop here
						// we check if somewhere before we can finish at j-1
						
						for (p=0;p<i;p++) {
							opt[i][j] = (opt[i][j]+opt[p][j-1])%10000;
						}
						
					}
				}
				
			}
			
			res = 0;
			
			for (i=0;i<M;i++) {
				res = (res+opt[i][18])%10000;
			}
			
			score = Integer.toString(res);
			
			while (score.length()<4) {
				score = '0'+score;
			}
			
			out.println("Case #"+k+": "+score);
			
		}
		
		out.close();
		System.exit(0);	
		
	}
	
}

