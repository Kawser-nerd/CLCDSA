import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	public void solve(){
		int n = in.nextInt();
		int m = in.nextInt();
		String[] s = new String[n];
		for(int i = 0;i<n;i++){
			s[i] = in.next();
		}
		String[] t = new String[m];
		for(int j = 0;j<m;j++){
			t[j] = in.next();
		}
		HashMap[] h = new HashMap[100000];
		int num = 1;
		int cou = 0;
		h[0] = new HashMap<String,Integer>();
		for(int i = 0;i<n+m;i++){
			String[] ss;
			if (i<n)
				ss = s[i].split("/");
			else
				ss = t[i-n].split("/");
			int cur = 0;
			for(int j = 1;j<ss.length;j++){
				if (h[cur].containsKey(ss[j])){
					cur = ((HashMap<String,Integer>)h[cur]).get(ss[j]); 
				} else {
					h[cur].put(ss[j],num);
					cur = num++;
					h[cur] = new HashMap<String,Integer>();
					if (i>=n) cou++;
					//out.println(ss[j]+" "+cou);
				}
			}
		}
		out.println(cou);
	}

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
			solve();
		}
	}

	public void close() throws Exception{
		out.close();
	}

	public static void main(String[]  args){
		new Thread(){
			public void run(){
				try{
					Main a = new Main();
					a.run();
					a.close();
				} catch (Exception E){
					throw new RuntimeException(E);
				}
			}
		}.start();
	}
}
