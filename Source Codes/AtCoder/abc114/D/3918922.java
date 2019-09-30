import java.util.ArrayList;
import java.util.Scanner;

class Main{
	static final long MOD = 1000000007;

	static int H, W, K;
	static long[][] dp = new long[110][10];
	static int ans = 0;
	static long n = 0;





	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		n = sc.nextLong();

		ArrayList<Integer> list = new ArrayList<Integer>();

		for(int i= 2; i <= n;i++){					//????
			boolean flag = true;
			for(int j = 2;j*j < i;j++){
				if(i%j == 0){
					flag = false;
					break;
				}
			}
			if(flag){
				list.add(i);
			}
		}

		int[] data = new int[list.size()];

		int p =0;
		while(true){						//????????????
			if(n == 0){
				break;
			}
			long x = n;
			p =0;
			while(true){
								if(x == 1){
					break;
				}
				if(x % list.get(p) == 0){
					data[p]++;
					x /= list.get(p);
				}else{
					p++;
				}
			}
			n--;
		}
		
//		for(int i = 0;i < data.length;i++){					//??
//			System.out.print(list.get(i) + " ");
//			System.out.println(data[i]);
//
//		}
		
		int c75 = 0;
		int c25 = 0;
		int c15 = 0;
		int c5 = 0;
		int c3 = 0;

		for(int i = 0;i < list.size();i++){

			if(data[i] >= 2){
				c3++;
			}
			if(data[i] >= 4){
				c5++;
			}
			if(data[i] >= 14){
				c15++;
			}
			if(data[i] >= 24){
				c25++;
			}
			if(data[i] >= 74){
				c75++;
			}
		}

		long ans = 0;
		ans += c75 + c25*(c3-1) + c15 * (c5-1) + (c5*(c5-1)/2)*(c3-2);
		System.out.println(ans);







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

		return end - otherpair.end;
	}
}