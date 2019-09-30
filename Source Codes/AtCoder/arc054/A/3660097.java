import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int L=sc.nextInt();
		int X=sc.nextInt();
		int Y=sc.nextInt();
		int S=sc.nextInt();
		int D=sc.nextInt();
		int tokei=0;
		int hantokei=0;
		if(D>S) {
			tokei=D-S;
			hantokei=L-D+S;
		}
		else if(S>D) {
			tokei=L-S+D;
			hantokei=S-D;
		}

		if(X>=Y) {
			System.out.println((double)tokei/(X+Y));
		}
		else {
			System.out.println(Math.min((double)tokei/(X+Y), (double)hantokei/(Y-X)));
		}
	}
}