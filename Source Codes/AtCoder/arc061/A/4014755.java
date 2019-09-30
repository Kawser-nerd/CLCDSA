import java.util.Scanner;

//????
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String N = sc.next();
		boolean[] flg = new boolean[N.length()-1];
		System.out.println(bits(flg,0,N));
	}
	//flag?true?????+???????????????index,
	public static long bits(boolean[] flg,int index,String s) {
		if (flg.length == index) {
			return calSum(flg,s);
		} else {
			long sum = 0;
			flg[index] = true;
			sum += bits(flg, index+1, s);
			flg[index] = false;
			sum += bits(flg, index+1, s);
			return sum;
		}
	}

	public static long calSum(boolean[] flg, String s) {
		long sum = 0;
		int start = 0;
		for (int i = 0; i < flg.length; i++) {
			if (flg[i]) {
				sum += Long.parseLong(s.substring(start, i+1));
				start = i+1;
			}
		}
		sum += Long.parseLong(s.substring(start, s.length()));
		return sum;
	}

}