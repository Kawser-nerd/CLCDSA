package con2014Q;

import java.io.*;
import java.util.*;

public class A {
	
//	private static final String islarge = "-large";
	private static final String fileName = "results/con2014Q/"+A.class.getSimpleName().toLowerCase();//+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	static final String BAD = "Bad magician!", CHEAT = "Volunteer cheated!";
	private void solve() {
		int R1 = in.nextInt();
		int possible = 0;
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				int n = in.nextInt();
				if(i==R1){
					possible|=(1<<n);
				}
			}
		}
		{
			R1 = in.nextInt();
			int possible2 = 0;
			for(int i=1;i<=4;i++){
				for(int j=1;j<=4;j++){
					int n = in.nextInt();
					if(i==R1){
						possible2|=(1<<n);
					}
				}
			}
			possible &= possible2;
		}
		if(possible == 0){
			out.println(CHEAT);
		}else {
			int res = -1;
			for(int i=0;i<=16;i++){
				if((possible & (1<<i))==0)continue;
				if(res!=-1){
					out.println(BAD);
					return;
				}
				res=i;
			}
			out.println(res);
		}
	}
	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new A().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
