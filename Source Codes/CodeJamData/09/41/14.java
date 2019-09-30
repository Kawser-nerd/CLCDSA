import java.util.*;
import java.text.*;
import java.io.*;
import java.util.regex.*;
import java.math.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
@SuppressWarnings("unchecked")
public class A{
	public static void main(String[] args) throws Exception{
		long time = System.currentTimeMillis();
		int T = INT(in.readLine());
		for(int i = 1; i <= T; i++){
			System.out.printf("Case #%d: ",i);
			new A().go();
		}
	//	System.out.printf("Time spent: %.3fs%n",(System.currentTimeMillis()-time)/1000.0);
	}
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int INT(Object o){ return Integer.parseInt(o.toString());}
	static void ST() throws Exception{ st = new StringTokenizer(in.readLine());}
	void go() throws Exception{
		int n = INT(in.readLine());
		int[] minrow = new int[n];
		for(int i = 0; i < n; i++){
			String s = in.readLine();
			for(int j = 0; j < s.length(); j++){
				if(s.charAt(j) == '1') minrow[i] = j;
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				if(minrow[j] <= i){
					ans += j-i;
					for(int k = j; k > i; k--){
						int tmp = minrow[k];
						minrow[k] = minrow[k-1];
						minrow[k-1] = tmp;
					}
					break;
				}
			}
		}
		System.out.println(ans);
	}

}