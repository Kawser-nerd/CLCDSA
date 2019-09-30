import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// ?????
		String S=sc.next();
		String[] sps1 =S.split("/");
		if (Integer.valueOf(sps1[0])>2019) {
			System.out.println("TBD");
		}
		else if (Integer.valueOf(sps1[0])==2019) {
			if (Integer.valueOf(sps1[1])>4) {
				System.out.println("TBD");
			}
			else {
				System.out.println("Heisei");
			}
		}
		else {
			System.out.println("Heisei");
		}
	  }
}