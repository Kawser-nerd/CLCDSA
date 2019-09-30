import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int kosu=sc.nextInt();
		long[] mati=new long[kosu];
		long aru=sc.nextLong();
		long tlp=sc.nextLong();
		for(int i=0; i<kosu; i++) {
			mati[i]=sc.nextLong();
		}
		long costs=0;

		for(int i=0; i<kosu-1; i++) {
			long a=mati[i+1]-mati[i];
			if(a*aru>tlp) {
				costs+=tlp;
			}
			else {
				costs+=a*aru;
			}
		}
		System.out.println(costs);
	}
}