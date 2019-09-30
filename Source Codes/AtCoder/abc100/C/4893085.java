import java.util.Scanner;


public class Main {
	static int N;
	static long[] T;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		 N = sc.nextInt();
		 T = new long[N];
		 for(int i = 0 ; i < N ; i++){
			 T[i]= sc.nextInt();
		 }
		 sc.close();


		 int count = 0 ;
		 int counti = 0 ;


		 for (long m : T){
			 //System.out.println("calc : " + m);
			 count += counti;
			 //System.out.println("count :"+count);

			 for(int i = 1; i < 35 ; i++){
				 long p = (long)Math.pow(2, i);

				 if(m%p==0){
					 counti = i;
					// System.out.println("counti : "+counti);
				 }
				 else if(m%2 !=0){
					 counti = 0 ;
					 break;
				 }


				 else {
					 break;
				 }
			 }
		}
		 count += counti;
		 System.out.println(count);
	}
}