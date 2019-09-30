import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {	
		Scanner sc = new Scanner(System.in);
		String n = sc.nextLine();
		String s = sc.nextLine();
		
		HashMap<String,String> alpha = new HashMap<String,String>();
		long count = 1;
		for(int i = 0;i < Integer.parseInt(n);i++) {
			char mark = s.charAt(i);
			if(alpha.containsKey(String.valueOf(mark))) {
				
			}else {
				alpha.put(String.valueOf(mark), "");
				int sum=0;
				for(int j=i;j<Integer.parseInt(n);j++ ) {
					if(s.charAt(j) == mark){
						sum++;
					}
				}
				count = count%1000000007;
				count *= sum+1;
			}
			
		}
		
		System.out.println((count-1)%1000000007);
	}
}