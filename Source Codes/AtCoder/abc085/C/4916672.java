import java.util.Scanner;


public class Main {
	static int N,Y;
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
			 N = sc.nextInt();
			 Y = sc.nextInt();
		  sc.close();

		  int sen = 0;
		  int gsen = 0;
		  int jsen = 0;

		  boolean f = false;

		  int pp = 10000*N;
		  if(pp == Y){
			  System.out.println(N + " 0 0");
		  }else{
			  int qq = pp-Y;
			  for(int i = 0 ; i < N+1 ; i++){
				  for(int j = 0 ; j < N+1 ; j++){
					  if(i + j > N){
						  continue;
					  }else if(5000 * i + 9000 * j == qq){
						  f = true;
						  gsen = i;
						  sen = j;
						  jsen = N-i-j;
						  break;

					  }else{
						  continue;
					  }
				  }
			  }

			  if(!f){
				  System.out.println("-1 -1 -1");
			  }else{
				  System.out.println(jsen + " " + gsen + " " + sen);
			  }
		  }
	}
}