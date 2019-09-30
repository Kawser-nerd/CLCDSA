import java.util.*;
import java.io.*;
import java.math.*;

public class A
{
	public static void main(String[] argv) throws IOException
	{
		new A().run();
	}
	Scanner in;
	PrintWriter out;

	double[] solve(int n, String[] table){
		int[] game_num;
		double[] wp, owp, oowp;
		game_num = new int[n];
		wp = new double[n];
		owp = new double[n];
		oowp = new double[n];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (table[i].charAt(j) != '.') game_num[i]++;
				if (table[i].charAt(j) == '1') wp[i] += 1.0;
			}
		}
		for (int i = 0; i < n; i++){
			int opnum = 0;
			for (int j = 0; j < n; j++){
				if (table[i].charAt(j) != '.'){
					opnum++;
					owp[i] += (wp[j] - (int)(table[j].charAt(i)-'0')) / (game_num[j] - 1);
				}
			}
			owp[i] /= opnum;
		}
		for (int i = 0; i < n; i++){
			int opnum = 0;
			for (int j = 0; j < n; j++){
				if (table[i].charAt(j) != '.'){
					opnum++;
					oowp[i] += owp[j];
				}
			}
			wp[i] /= game_num[i];
			oowp[i] /= opnum;
		}
		double[] res = new double[n];
		for (int i = 0; i < n; i++){
			//System.out.println(wp[i] + " " + owp[i] + " " + oowp[i]);
			res[i] = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i];
		}
		return res;
	}

	public void run() throws IOException
	{
		boolean oj = System.getProperty("ONLINE_JUDGE") != null;
		in = oj ? new Scanner(System.in) : new Scanner(new File("input.txt"));
		out = oj ? new PrintWriter(System.out) : new PrintWriter(new File("output.txt"));

		int testNum = in.nextInt();
		for (int t = 0; t < testNum; t++){
			int n = in.nextInt();
			String[] table = new String[n];
			for (int i = 0; i < n; i++){
				table[i] = in.next();
			}
			out.println("Case #" + (t+1) + ":");
			double[] res = solve(n, table);
			for (int i = 0; i < n; i++) out.println(res[i]);
			out.flush();
		}
	}
}
