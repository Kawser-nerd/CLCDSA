import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class A2 {
	static Vector<String> dict, ss;
	
	static int L,D,N;
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("testin"));
		FileWriter fw = new FileWriter("testoutA");
		StringTokenizer st = new StringTokenizer(in.readLine());
		L = new Integer(st.nextToken()); 
		D = new Integer(st.nextToken());
		N = new Integer(st.nextToken());
		dict = new Vector<String>();
		for (int i = 0; i < D; i++) {
			dict.add(in.readLine().trim());
		}
		for (int cases = 1; cases <= N; cases++) 
		{
			String s = in.readLine();
			ss = new Vector<String>();
			for (int i = 0; i < s.length(); i++) 
			{
				int j = i+1;
				if(s.charAt(i) == '(')
				{
					String tok = "";
					for (; s.charAt(j) != ')'; j++) {
						tok += s.charAt(j);
					}
					ss.add(tok);
					i = j;
				}
				else
					ss.add("" + s.charAt(i));
			}
			int ans = 0;
			for(String d: dict)
			{
				boolean ok = true;
				for (int i = 0; i < d.length() && ok; i++) {
					if(!ss.get(i).contains(""+d.charAt(i)))
						ok = false;
				}
				if(ok)
					ans++;
			}
			String out = "Case #" + cases + ": " + ans;
			System.out.println(out);
			fw.write(out + "\n");
		}
		fw.flush();
		fw.close();
	}
}

