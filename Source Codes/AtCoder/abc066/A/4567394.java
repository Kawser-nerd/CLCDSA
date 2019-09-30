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
		int a[] = new int[3];
		for(int i=0;i<3;i++){
			a[i] = Integer.parseInt(sc.next());
		}
		Arrays.sort(a);
		out.println(a[0]+a[1]);
		
		out.flush();	
	}
}