import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {	
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.nextLine());
		ArrayList<Integer> result = new ArrayList<Integer>();
		ArrayList<Integer> res = new ArrayList<Integer>();
		String tmp = sc.nextLine();
		String[] s = tmp.split(" ");
		
		for(int i=0;i<n;i++) {
			res.add(Integer.parseInt(s[i]));
		}
		
		
		for(int i=1;i<=n;i++) {
			for(int j=res.size();j>0;j--){
				if(res.get(j-1) == j) {
					result.add(j);
					res.remove(j-1);
					break;
				}
				
				
			}
			
		}
		if(res.size()==0) {
			for(int i=n-1;i>=0;i--) {
				System.out.println(result.get(i));
			}
			
		}else {
			System.out.println(-1);
		}
		
		
		
		
	}
	
	
}