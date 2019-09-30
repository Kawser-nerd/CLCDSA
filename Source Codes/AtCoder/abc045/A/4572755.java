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
		int A = Integer.parseInt(sc.next());
      int B = Integer.parseInt(sc.next());
      int C = Integer.parseInt(sc.next());
      out.println((A+B)*C/2);
		out.flush();	
	}
}