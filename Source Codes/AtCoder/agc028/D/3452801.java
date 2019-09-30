//package atcoder028D;
import java.util.stream.*;
import java.util.function.Supplier;
import java.util.function.BiFunction;
import java.util.*;
interface Computations{
	final static int MOD = 1000000007;
	final static BiFunction <Integer, Integer, Integer> Add = (x, y) ->  (x + y) >= MOD ? (x + y - MOD) : (x + y);
	final static BiFunction <Integer, Integer, Integer> Mul = (x, y) -> (int)(((1L * x * y) % MOD));
	final static BiFunction<Integer, Integer, Integer> Sub = (x, y) -> (x - y) < 0 ? (x - y + MOD) : (x - y);
	static Integer operate(Integer x, Integer y, BiFunction <Integer, Integer, Integer> op) {
		return op.apply(x, y);
	}
}
class PartialCompute implements Computations{
	private List <Integer> Partial;
	//final static private int MOD = 1000000007; 
	PartialCompute(int sz){
		//MOD = mod;
		Supplier <List <Integer> > supplier = () -> new ArrayList<Integer>();
		//Partial = Stream.iterate(0, n -> n).limit(sz).collect(Collectors.toCollection(supplier));
		Partial = new ArrayList<Integer>();
		for(int i = 1; i <= sz; i++)
			Partial.add(0);
	}
	public void setVal(int pos, int val) {
		Partial.set(pos, val);
	}
	public void precalcPartialSum() {
		for(int i = 1; i < Partial.size(); i++) {
			Partial.set(i, Computations.operate(Partial.get(i), Partial.get(i - 1), Add));
		}
	}
	public void precalcPartialProd() {
		Partial.set(0, 1);
		for(int i = 2; i < Partial.size(); i++) {
			Partial.set(i, i - 1);
			Partial.set(i, Computations.operate(Partial.get(i), Partial.get(i - 2), Mul));
		}
	}
	public int getSum(int a, int b) {
		return Computations.operate(Partial.get(b), Partial.get(a - 1), Sub);
	}
	public int getProd(int pos) {
		return Partial.get(pos);
	}
}
public class Main implements Computations{
	static int N, K;
	static PartialCompute Psum = new PartialCompute(1205);
	static PartialCompute Pprod = new PartialCompute(1205);
	static PartialCompute Prand = new PartialCompute(1205);
	static int[][] DP = new int[1205][1205];
	static int ans = 0;
	static private void Read() {
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		K = in.nextInt();
		for(int i = 1; i <= 4 * N; i++) {
			Psum.setVal(i, 1);
		}
		Random rnd = new Random();
		for(int i = 1; i <= K; i++) {
			int x = in.nextInt(), y = in.nextInt();
			Psum.setVal(x, 0);
			Psum.setVal(y, 0);
			Psum.setVal(x + N * 2 , 0);
			Psum.setVal(y + N * 2, 0);
			int r = rnd.nextInt(MOD);
			Prand.setVal(x, r);
			Prand.setVal(x + 2 * N, r);
			Prand.setVal(y, MOD - r);
			Prand.setVal(y + 2 * N, MOD - r);
		}
		in.close();
	}
	static private void precalcP() {
		Psum.precalcPartialSum();
		Pprod.precalcPartialProd();
		Prand.precalcPartialSum();
	}
	static private void solveDP() {
		for(int dist = 1; dist < N * 2; dist += 2) {
			for(int i = 1; i <= N * 2; i++) {
				int j = i + dist;
				if(Prand.getSum(i, j) != 0)
					continue;
				int sum = Psum.getSum(i, j);
				int p = Pprod.getProd(N * 2 - 2 * K - sum);
				DP[i][j] = Pprod.getProd(sum);
				if(dist != 2 * N - 1) {
					for(int k = j - 1; k > i; k--) {
						int aux = Pprod.getProd(Psum.getSum(k + 1, j));
						aux = Computations.operate(DP[i][k], aux, Mul);
						DP[i][j] = Computations.operate(DP[i][j], aux, Sub);
					}
				}
				
				if(dist == N * 2 - 1) {
					for(int k = 2; k < 2 * N + 1; k++) {
						for(int l = 2 * N; l - k < 2 * N - 1; l++) {
							sum = Psum.getSum(k, l);
							int p2 = Pprod.getProd(N * 2 - 2 * K - sum);
							int aux = Computations.operate(DP[k][l], p2, Mul);
							//aux = Computations.operate(DP[k][2 * N + 1], aux, Mul);
							DP[i][j] = Computations.operate(DP[i][j], aux, Sub);
						}
						
					}
				}
				ans = Computations.operate(ans, Computations.operate(DP[i][j], p, Mul), Add);
				if(dist == N * 2 - 1 && i == 1)
					return;
			}
		}
	}
	public static void main(String args[]) {
		Read();
		precalcP();
		solveDP();
		System.out.println(ans);
	}
}