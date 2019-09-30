import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		String list[][] = new String[N][2];
		for(int s=0; s<N; s++){
			for(int t=0; t<2; t++){
				list[s][t] = sc.next();
			}
		}

		double sum = 0;

		for(int i=0; i<N; i++){
			if(list[i][1].matches("JPY")){
				sum +=  Double.parseDouble(list[i][0]);
			}else{
				sum +=  Double.parseDouble(list[i][0]) * 380000;
			}
		}
		
		System.out.println(sum);
    }
}