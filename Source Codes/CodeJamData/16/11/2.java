import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int N = Integer.parseInt(br.readLine());

		for(int p = 0; p < N; p++) {
			String s = br.readLine();
			String ret = "";
			if(s.length() > 0) {
				ret = ret + s.charAt(0);
				for(int i = 1; i < s.length(); i++) {
					if((int)ret.charAt(0) > s.charAt(i)) {
						ret = ret + s.charAt(i);
					} else {
						ret= s.charAt(i) + ret;
					}
				}
			}

			pw.println("Case #" + (p+1) + ": " + ret);
		}


		pw.flush();
		pw.close();

	}
}