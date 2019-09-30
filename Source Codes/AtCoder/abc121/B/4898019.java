import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int M = sc.nextInt();
		int C = sc.nextInt();

		int Blist[] = new int[M];
		for(int i=0; i<Blist.length; i++){
			Blist[i] = sc.nextInt();
		}

		int Alist[][] = new int[N][M];
		for(int s=0; s<N; s++){
			for(int t=0; t<M; t++){
				Alist[s][t] = sc.nextInt();
			}
		}

		int answer = 0;
		for(int x=0; x<N; x++){
			int sum = 0;
			for(int y=0; y<M; y++){
					sum += Alist[x][y] * Blist[y];
			}
			sum += C;
			if(sum > 0){
				answer++;
			}
		}

		System.out.println(answer);
    }
}