import java.io.*;
import java.util.*;

public class Main{

	BufferedReader in;
	PrintWriter out;

	String curs;
	int curp;

	double[] p;
	int[] left;
	int[] right;
	String[] str;

	int last;

	public char nextCh() throws Exception{
		if (curp>=curs.length()){
			curs = in.readLine()+" ";
			curp = 0;
		}
		return curs.charAt(curp++);
	}

	public String nextToken() throws Exception{
		String s = "";
		char c = nextCh();
		while (c<=32){
			c = nextCh();
		}
		s = ""+c;
		if (c=='(' || c==')'){ 
			return s;
		}
		while (true){
			c = nextCh();
			if (c==')' || c=='(' || c<=32){
				curp--; return s;
			}
			s = s+c;
		}
	}

	public int poisk() throws Exception{
		String s = nextToken();
		int cur = last++;
		p[cur] = Double.parseDouble(s);
		s = nextToken();
		if (s.equals(")")){
			left[cur]=-1;
			right[cur]=-1;
		} else {
			str[cur] = s; if (!nextToken().equals("(")) throw new Exception("B2");
			left[cur] = poisk();if (!nextToken().equals("(")) throw new Exception("B2");
			right[cur] = poisk();
			if (!nextToken().equals(")")) throw new Exception("B3");
		}
		return cur;
	}


	public void run() throws Exception{
		in = new BufferedReader(new FileReader("input.txt"));
		out= new PrintWriter(new FileWriter(new File("output.txt")));
		curs = in.readLine()+" ";
		curp = 0;
		int _ = Integer.parseInt(nextToken());
		left = new int[1000];
		right = new int[1000];
		str = new String[1000];
		p  = new double[1000];
		for(int __=0;__<_;__++){
			out.println("Case #"+(__+1)+":");
			int l = Integer.parseInt(nextToken());
			last = 0;
			if (!nextToken().equals("(")) throw new Exception("B1");
			poisk();
			int k = Integer.parseInt(nextToken());
			for(int i = 0;i<k;i++){
				nextToken();
				HashSet<String> h = new HashSet<String>();
				int z = Integer.parseInt(nextToken());
				for(int j = 0;j<z;j++)
					h.add(nextToken());
				int cur = 0;
				double pp = p[cur];
				while (left[cur]!=-1){
					if (h.contains(str[cur])){
						cur = left[cur];
					} else {
						cur = right[cur];
					}
					pp = pp*p[cur];
				}
				out.println(pp);
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
