import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		sc.close();
		int count = 0;
		for(long l = A;l <= B;l++) {
			String s = String.valueOf(l);
			String[] ss = s.split("");
			if(ss[0].equals(ss[4]) && ss[1].equals(ss[3])) count++;
		}
		System.out.println(count);
	}

}