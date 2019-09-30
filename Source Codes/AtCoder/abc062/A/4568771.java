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
		String a[] = {"1","3","5","7","8","10","12"};
		String b[] = {"4","6","9","11"};
		String c[] = {"2"};
		String A = sc.next();
		String B = sc.next();
		if((Arrays.asList(a).contains(A) && Arrays.asList(a).contains(B))
		|| (Arrays.asList(b).contains(A) && Arrays.asList(b).contains(B))
		|| (Arrays.asList(c).contains(A) && Arrays.asList(c).contains(B))){
			out.println("Yes");
		}else {
			out.println("No");
		}
		out.flush();	
	}
}