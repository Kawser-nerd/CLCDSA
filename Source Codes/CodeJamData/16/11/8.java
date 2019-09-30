import java.util.*;
import java.io.*;

public class A {
	
	public static void main(String[] args) throws IOException {
		
		Scanner qwe = new Scanner(System.in);
		PrintWriter out = new PrintWriter("A.out");
		
		
		int T  = qwe.nextInt();
		
		for(int cse = 1; cse <= T; cse++){
			char[] S = qwe.next().toCharArray();
			
			ArrayDeque<Character> dq = new ArrayDeque<Character>();
			
			dq.addFirst(S[0]);
			for (int i = 1; i < S.length; i++) {
				
				if(dq.peek() <= S[i])
					dq.addFirst(S[i]);
				else dq.addLast(S[i]);
				
			}
			
			StringBuilder stb =  new StringBuilder("");
			
			while(!dq.isEmpty()){
				stb.append(dq.poll());
			}
			
			
			out.println("Case #"+cse+": "+stb);
		}
		
		
		out.close();
		qwe.close();
	}

}
