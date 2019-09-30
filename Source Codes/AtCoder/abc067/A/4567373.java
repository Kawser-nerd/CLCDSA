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
		int M = Integer.parseInt(sc.next());
		if(N%3==0 || M%3==0 || (N+M)%3 ==0){
			out.println("Possible");
		}else{
			out.println("Impossible");
		}
		out.flush();	
	}
}