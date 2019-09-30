import java.util.*;
import java.text.*;
import java.io.*;
import java.util.regex.*;
import java.math.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
@SuppressWarnings("unchecked")
public class C{
	public static void main(String[] args) throws Exception{
		long time = System.currentTimeMillis();
		new C().go();
	//	System.out.printf("Time spent: %.3fs%n",(System.currentTimeMillis()-time)/1000.0);
	}
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int INT(Object o){ return Integer.parseInt(o.toString());}
	static void ST() throws Exception{ st = new StringTokenizer(in.readLine());}
	void go() throws Exception{
		int T = INT(in.readLine());
		for(int t = 1; t <= T; t++){
			ST();
			C = INT(st.nextToken());
			N = INT(st.nextToken());
			dp = new double[C+1];
			System.out.print(String.format("Case #%d: %.7f%n",t,doit(0)).replace(',','.'));
		}
	}
	int C, N;

	double[] dp;
	double doit(int have){
		if(dp[have] != 0) return dp[have]-1;
		if(have == C) return 0;
		double ret = 0;
		double nothingP = go(C, C-have, 0, N);
		ret += 1.0/(1-nothingP);
		for(int i = 1; i <= N && have+i <= C; i++){
			ret += go(C, C-have, i, N)*(doit(have+i))/(1-nothingP);
		}
		dp[have] = ret+1;
		return ret;
	}

	double[][][][] memo = new double[41][41][41][41];
	double go(int tot, int missing, int need, int picks){
		if(need > picks) return 0;
		if(need < 0) return 0;
		if(picks == 0) return 1;
		if(memo[tot][missing][need][picks] != 0) return memo[tot][missing][need][picks]-1;
		double p = missing/(double)tot;
		double ret = p*go(tot-1, missing-1, need-1, picks-1) + (1-p)*go(tot-1, missing, need, picks-1);
		memo[tot][missing][need][picks] = ret+1;
	//	System.out.printf("go(%d,%d,%d,%d) = %.2f%n",tot,missing,need,picks,ret);
		return ret;
	}
}