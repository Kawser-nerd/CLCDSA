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
		if(A+B>=10){
			out.println("error");
		}else {
			out.println(A+B);
		}
		out.flush();	
	}
}