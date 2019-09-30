import java.util.*;
import java.io.*;

public class B {
	
	public static void main(String[] args) throws IOException {
		
		Scanner qwe = new Scanner(System.in);
		PrintWriter out = new PrintWriter("B.out");
		
		
		int T  = qwe.nextInt();
		
		for(int cse = 1; cse <= T; cse++){
			int N = qwe.nextInt();
			
			int[] counts =  new int[2501];
			
			for (int i = 0; i < 2*N-1; i++) {
				
				for (int j = 0; j < N; j++) {
					counts[qwe.nextInt()]++;
				}
				
			}
			
			
			out.print("Case #"+cse+": ");
			for (int i = 0; i < counts.length; i++) {
				if(counts[i] % 2 == 1) out.print(i+" ");
			}
			out.println();
			
		}
		
		
		out.close();
		qwe.close();
	}

}
