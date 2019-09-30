import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????

		Scanner scan=new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int N=scan.nextInt();

		int max=0;
		int id=0;
		int max_;
		for(int i=2;i<=N;i++){
			out.printf("? %d %d\n", 1, i);
			out.flush();
			scan = new Scanner(System.in);
			max_=scan.nextInt();
			if(max_>max){
				id=i;
				max=max_;
			}
		}

		for(int i=2;i<=N;i++){

			if(i!=id){
				out.printf("? %d %d\n", id, i);
				out.flush();
				scan = new Scanner(System.in);
				max_=scan.nextInt();
				if(max_>max){
					max=max_;
				}
			}
		}


		out.printf("! %d\n",max);
		out.flush();
	}

}