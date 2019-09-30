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
		int O = Integer.parseInt(sc.next());
		if(O>=N && O<=M){
			out.println("Yes");
		}else{
			out.println("No");
		}
		out.flush();	
	}
}