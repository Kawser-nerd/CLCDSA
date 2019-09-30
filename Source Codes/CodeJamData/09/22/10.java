import java.io.*;
import java.util.*;

public class Main{

	BufferedReader in;
	PrintWriter out;

	public void run() throws Exception{
		in = new BufferedReader(new FileReader("input.txt"));
		out= new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = Integer.parseInt(in.readLine());
		int[] d = new int[10];
		for(int __=0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
			String s = in.readLine();
			int cur = s.length()-1;
			char c = s.charAt(cur--);
			Arrays.fill(d,0);
			d[c-'0']++;
			while (cur>=0){
				d[s.charAt(cur)-'0']++;
				if (c<=s.charAt(cur)){
					c = s.charAt(cur);
					cur--;
				} else {
					c = s.charAt(cur);
					for(int i = 0;i<cur;i++)
						out.print(s.charAt(i));
					int p = c-'0'+1;
					while (d[p]==0) p++;
					out.print(p); d[p]--;
					for(int i = 0;i<=9;i++)
						for(int j = 0;j<d[i];j++)
							out.print(i);
					out.println();
					break;

				}

			}
			if (cur<0){
				for(int i = 1;i<=9;i++)
					if (d[i]!=0){
						out.print(i); d[i]--; out.print(0); break;
					}
				for(int i = 0;i<=9;i++)
					for(int j = 0;j<d[i];j++)
						out.print(i);
				out.println();
			}
		}
	}

	public void close() throws Exception{
		out.close();
	}

	public static void main(String[] args){
		new Thread(){
			public void run(){
				try{
					Main a = new Main();
					a.run();
					a.close();
				} catch (Exception E){
					System.out.println(E);
					throw new RuntimeException(E);
				}
			}
		}.start();
	}
}
