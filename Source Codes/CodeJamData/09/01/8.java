import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class AlienLanguage {
	
	public static void main(String[] args) throws Exception {
		int i,j,k;
		int L, D, N;
		char c;
		String line;
		boolean bracket, good;
		int score;
		
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-large.out")));
		
		StringTokenizer st;
		
		line = br.readLine();
		
		st = new StringTokenizer(line);
		
		L = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		char word[][] = new char[D][L];
		
		// first we read the dictionary
		for (i=0;i<D;i++) {
			line = br.readLine();
			for (j=0;j<L;j++) {
				word[i][j] = line.charAt(j);
			}
		}
		
		for (i=1;i<=N;i++) {
			line = br.readLine();
			
			// the default falue is false
			boolean b[][] = new boolean[L][26];
			
			st = new StringTokenizer(line);
			
			k = 0;
			bracket = false;
			for (j=0;j<line.length();j++) {
				
				c = line.charAt(j);
				
				if (bracket == false) {
					
					// there can't be ')' character here
					
					if (c == '(') {
						bracket = true;
					} else {
						
						b[k][(int)(c)-(int)('a')] = true;
						k++;
						
					}
					
				} else {
					
					if (c == ')') {
						bracket = false;
						// we have finished with this letter
						k++;
					} else {
						
						b[k][(int)(c)-(int)('a')] = true;
						
					}
					
				}
			}
			
			// here we use the results
			score = 0;
			
			for (j=0;j<D;j++) {
				good = true;
				for (k=0;k<L;k++) {
					if (b[k][(int)word[j][k]-(int)('a')] == false) {
						good = false;
						break;
					}
				}
				if (good == true) {
					score++;
				}
			}
			
			out.println("Case #"+i+": "+score);
			
		}
		
		out.close();
		System.exit(0);	
		
	}
	
}

