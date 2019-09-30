import java.io.*;
import java.util.*;

public class Main{
	
	public void run() throws Exception{
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			int n = in.nextInt();
			int m = in.nextInt();
			int a = in.nextInt();
			boolean ok = false;
			out.print("Case #"+(__+1)+": ");
			for (int i = 0;i<=n;i++){
				for(int j = 0;j<=n;j++)
					for(int k =0;k<=m;k++)
						for(int l =0;l<=m;l++)
							if (Math.abs(i*l-j*k)==a && !ok){
								out.println(0+" "+0+" "+i+" "+k+" "+j+" "+l);
								ok = true;
								break;
							}
			}
			if (!ok) out.println("IMPOSSIBLE");
		}
		out.close();
	}
	
	public static void main(String[] args) throws Exception{
		new Main().run();
	}
}