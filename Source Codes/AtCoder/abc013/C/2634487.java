import java.util.Scanner;

public class Main {
	static long N,H,W,bmax,kingaku;
	static long ayen,bup,cyen,dup,edown;

	public static void main(String[] args) {

		scanning();
		bup += edown;
		dup += edown;
		W =  N * edown - H;
		bmax = W / bup + 1;

		if(W > 0) {
			long Wtemp;
			kingaku = bmax * ayen;
			for(long i = 0; i < bmax;i++) {
				Wtemp = W - i * bup;
				kingaku = min(kingaku,i * ayen + (Wtemp / dup + 1) * cyen);
			}
		}

		System.out.println(kingaku);
	}



	public static void scanning() {
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		H = scan.nextInt();
		ayen = scan.nextInt();
		bup = scan.nextInt();
		cyen = scan.nextInt();
		dup = scan.nextInt();
		edown = scan.nextInt();
		scan.close();
	}

	public static long min(long x,long y) {
		return x > y ? y : x;
	}

}