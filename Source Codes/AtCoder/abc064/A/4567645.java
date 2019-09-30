import java.io.PrintWriter;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		//String S = sc.next();
		//int N = Integer.parseInt(sc.next());
		//out.println();
		// ArrayList<String> list = new ArrayList<String>();
		// list.stream().sorted().distinct();
		int N = Integer.parseInt(sc.next());
		int A = Integer.parseInt(sc.next());
		int B = Integer.parseInt(sc.next());
		int cnt = N*100 + A*10 + B;
		if(cnt%4==0){
			out.println("YES");
		}else {
			out.println("NO");
		}
		out.flush();	
	}
}