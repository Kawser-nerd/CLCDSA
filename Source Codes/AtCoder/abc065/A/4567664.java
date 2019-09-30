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
		if(A>=B){
			out.println("delicious");
		}else if(N>=(B-A)){
			out.println("safe");
		}else if(N < (B-A)){
			out.println("dangerous");
		}
		out.flush();	
	}
}