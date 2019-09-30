import java.util.Scanner;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Yen = sc.nextInt();
		e: for(int x = 0; x <= N; x++){
			for(int y = 0; y <= N; y++){
				int z = N - x - y;
				if((z >= 0) &&(1000*z + 5000*y + 10000*x == Yen)){
					System.out.println(x+" "+y+" "+z);
					break e;
				}else if((x == N) && (y == N)){
					System.out.println("-1 -1 -1");
				}
			}
		}
	}
}