import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz=1; zz <= T;zz++){
			int X = in.nextInt();
			int S = in.nextInt();
			int R = in.nextInt();
			int t = in.nextInt();
			int N = in.nextInt();
			int[] length = new int[1000];
			int total = X;
			for(int i = 0; i < N;i++){
				int begin = in.nextInt();
				int end = in.nextInt();
				int speed = in.nextInt();
				length[speed+S] += end-begin;
				total -= end-begin;
			}
			length[S] += total;
			double left = t;
			double ans = 0;
			for(int i = 0; i < length.length;i++){
				double v = i;
				double nv = v+(R-S);
				double len = length[i];
				if(len/nv <= left){
					left -= len/nv;
					ans += len/nv;
				}else{
					ans += (len-(R-S)*left)/v;
					left = 0;
				}
			}
			System.out.format("Case #%d: %.09f\n", zz, ans);
		}
	}
}
