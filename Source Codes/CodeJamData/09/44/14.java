import java.util.*;
import java.text.*;
import java.io.*;
import java.util.regex.*;
import java.math.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
@SuppressWarnings("unchecked")
public class D{
	public static void main(String[] args) throws Exception{
		long time = System.currentTimeMillis();
		int T = INT(in.readLine());
		for(int i = 1; i <= T; i++){
			System.out.printf("Case #%d: ",i);
			new D().go();
		}
	//	System.out.printf("Time spent: %.3fs%n",(System.currentTimeMillis()-time)/1000.0);
	}
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int INT(Object o){ return Integer.parseInt(o.toString());}
	static void ST() throws Exception{ st = new StringTokenizer(in.readLine());}
	void go() throws Exception{
		int n = INT(in.readLine());
		double[] xs = new double[n];
		double[] ys = new double[n];
		double[] rs = new double[n];
		double ret = 0;
		for(int i = 0; i < n; i++){
			ST();
			xs[i] = INT(st.nextToken());
			ys[i] = INT(st.nextToken());
			rs[i] = INT(st.nextToken());
			ret = max(ret, rs[i]);
		}
		if(n < 3){
			System.out.println(ret);
			return;
		}
		double best = 1e20;
		for(int i = 0; i < 3; i++){
			int a = (i+1)%3;
			int b = (i+2)%3;
			best= min(best, (sqrt((xs[a]-xs[b])*(xs[a]-xs[b]) + (ys[a]-ys[b])*(ys[a]-ys[b])) + rs[a] + rs[b])/2);
		}
		System.out.println(max(ret, best));
	}
}