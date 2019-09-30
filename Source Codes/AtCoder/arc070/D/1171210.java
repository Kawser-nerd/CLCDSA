import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Scanner in;
	static PrintWriter out;
	static String INPUT = "";
	
	static boolean get(int a, int b)
	{
		out.println("? " + a + " " + b);
		out.flush();
		return in.next().charAt(0) == 'Y';
	}
	
	static void solve()
	{
		int A = ni(), B = ni();
		if(A <= B){
			out.println("Impossible");
			return;
		}
		int n = A+B;
		int[] stack = new int[n];
		int sp = 0;
		for(int i = 0;i < n;i++){
			stack[sp++] = i;
			if(sp >= 2){
				if(!get(stack[sp-2], stack[sp-1])){
					sp -= 2;
				}
			}
		}
		assert sp-1 >= 0;
		int honest = stack[sp-1];
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < n;i++){
			if(get(honest, i)){
				sb.append(1);
			}else{
				sb.append(0);
			}
		}
		out.print("! ");
		out.print(sb);
		out.println();
		out.flush();
	}
	
	public static void main(String[] args) throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	static int ni() { return Integer.parseInt(in.next()); }
	static long nl() { return Long.parseLong(in.next()); }
	static double nd() { return Double.parseDouble(in.next()); }
	static void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}