import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		long k = sc.nextLong();
		int work = -1;
		for(int i = 0; i < s.length() && i < k; i++){
			work = Integer.parseInt(s.substring(i,i+1));
			if(work != 1) break;
		}
		System.out.print(work);
	}
}