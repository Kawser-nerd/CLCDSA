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
		String A =sc.next();
		String B =sc.next();
		String C =sc.next();
		if(A.charAt(A.length()-1)==B.charAt(0) &&
		B.charAt(B.length()-1)==C.charAt(0)){
			out.println("YES");
		}else{
			out.println("NO");
		}

		out.flush();	
	}
}