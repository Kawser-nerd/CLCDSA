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
		int cnt =1;
		for(int i=0;i<N;i++){
			cnt *=100;
		}
      	if(M==100){
        	out.println(cnt*M+cnt);
        }else{
			out.println(cnt*M);
        }
          out.flush();	
	}
}