import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static class Pair implements Comparable<Pair>{
		int x;
		int y;
		int dif;
		Pair(int a,int b){
			x = a;
			y = b;
			dif = a-b;
		}
		@Override
		public int compareTo(Pair o) {
			if(dif < 0 && o.dif < 0){
				return x - o.x;
			}
			else if(dif < 0 && o.dif >= 0){
				return -1;
			}
			else if(dif >= 0 && o.dif <0){
				return 1;
			}
			else{
				return o.y - y;
			}
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int n = in.nextInt();

		Pair[] x = new Pair[n];

		for(int i=0;i<n;i++){
			x[i] = new Pair(in.nextInt(),in.nextInt());
		}

		Arrays.sort(x);

		long tmpMax = 0;
		long tmp=0;

		for(int i=0;i<n;i++){
			tmp += x[i].x;
			if(tmpMax < tmp){
				tmpMax = tmp;
			}
			tmp -= x[i].y;
		}

		System.out.println(tmpMax);

	}

}