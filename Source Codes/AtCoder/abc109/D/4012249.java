import java.util.ArrayList;
import java.util.Scanner;

class Main{



	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int H = sc.nextInt();
		int W = sc.nextInt();
		int[][] a = new int[H][W];
		for(int i = 0;i < H ;i++){
			for(int j = 0;j < W;j++){
				a[i][j] = sc.nextInt();
			}
		}
		ArrayList<Pair> pairs = new ArrayList<Pair>();
		int count = 0;
		for(int i = 0;i < H ;i++){
			for(int j = 0;j < W;j++){
				if(a[i][j]%2 == 1){

					if(j+1 < W){
						Pair pair1 = new Pair();
						pair1.from = i+1;
						pair1.end = j+1;
						pairs.add(pair1);

						
						Pair pair2 = new Pair();
						pair2.from = i+1;
						pair2.end = j+2;
						pairs.add(pair2);


						
						a[i][j+1]++;
						a[i][j]--;
						count++;

					}else if(i+1<H ){
						Pair pair1 = new Pair();
						pair1.from = i+1;
						pair1.end = j+1;
						pairs.add(pair1);

						
						Pair pair2 = new Pair();
						pair2.from = i+2;
						pair2.end = j+1;
						pairs.add(pair2);
						a[i+1][j]++;
						a[i][j]--;
						count++;
					}
				}
			}
		}
//				for(int i = 0;i < H ;i++){
//					for(int j = 0;j < W;j++){
//						System.out.print(a[i][j] + " ");	
//					}
//					System.out.println();	
//				}
		System.out.println(count);
		for(int i = 0;i < pairs.size();i=i+2){
			System.out.print(pairs.get(i).from + " " + pairs.get(i).end);
			System.out.println(" "+pairs.get(i+1).from + " " + pairs.get(i+1).end);

		}

	}

	static long gcd(long a,long b){
		if(b == 0){
			return a;
		}else{
			return gcd(b, a%b);
		}
	}



}




class Pair implements Comparable{
	int from;		//p
	int end;		//y
	int num;
	int bango;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return from - otherpair.from;
	}
}