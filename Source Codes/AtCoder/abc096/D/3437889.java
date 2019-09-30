import java.util.Scanner;

class Main{

	static char[][] map;
	static int H;
	static int W;

	public static void main(String[] args) {



		Scanner sc = new Scanner(System.in);			//?????
		int N = sc.nextInt();
		int[] data = new int [10000001];
		
		int c = 0;
		
		for(int i = 10;i <= 55555;i++){
			for(int j = 2;j <= (i+1)/2;j++){
				if(i % j == 0){
					break;
				}
				if(j == (i + 1)/2 && i % 5 == 1) {
					data[c] = i;
					c++;
					if(c == N){
						for(int k = 0;k < N;k++){
							System.out.println(data[k]);
						}
						return;

					}
				}
				
			}
		}

	}
}




class Pair implements Comparable{
	String from;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}