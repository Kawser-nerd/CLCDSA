import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.IntStream;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	private void solve() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long A = sc.nextLong();
		long B = sc.nextLong();
		long[] h = new long[N];
		for (int i = 0; i < N; i++) {
			h[i] = sc.nextLong();
		}
		long ok = 1000000000;
		long ng = 0;
		while (ok > ng + 1) {
			long test = (ok + ng) / 2;
			long num = 0;
			for (int i = 0; i < N; i++) {
				if (test * B < h[i]) {
					num += (h[i] - (test * B) + (A - B - 1)) / (A - B);
				}
			}
			if (num <= test) {
				ok = test;
			} else {
				ng = test;
			}
		}
		System.out.println(ok);
	}

	interface CombCalculator {
		long comb(int n, int m);
	}

	/**
	 * ????????????????????(MOD??)
	 * ????????????????????????
	 * C(N, N) % M ????? O(1)? ????O(max(N, logM))???
	 * size?1e8????????????MLE??????????
	 * ???????MOD??????????(????????????????????????)?
	 */
	class FactorialTableCombCalculator implements CombCalculator {
		int size;
		long[] factorialTable;
		long[] inverseFactorialTable;
		long mod;

		public FactorialTableCombCalculator(int size, long mod) {
			this.size = size;
			factorialTable = new long[size + 1];
			inverseFactorialTable = new long[size + 1];
			this.mod = mod;

			factorialTable[0] = 1L;
			for (int i = 1; i <= size; i++) {
				factorialTable[i] = (factorialTable[i - 1] * i) % mod;
			}
			inverseFactorialTable[size] = inverse(factorialTable[size], mod);
			for (int i = size - 1; i >= 0; i--) {
				inverseFactorialTable[i] = (inverseFactorialTable[i + 1] * (i + 1)) % mod;
			}
		}

		private long inverse(long n, long mod) {
			return pow(n, mod - 2, mod);
		}

		private long pow(long n, long p, long mod) {
			if (p == 0) {
				return 1L;
			}
			long half = pow(n, p / 2, mod);
			long ret = (half * half) % mod;
			if (p % 2 == 1) {
				ret = (ret * n) % mod;
			}
			return ret;
		}

		@Override
		public long comb(int n, int m) {
			if (n > size) {
				throw new RuntimeException("n is greater than size.");
			}
			if (n < 0 || m < 0 || n < m) {
				return 0L;
			}
			return (((factorialTable[n] * inverseFactorialTable[m]) % mod) * inverseFactorialTable[n - m]) % mod;
		}
	}

	/**
	 * ??????????????????????(MOD??)
	 * ????O(N^2), comb?O(1)???????
	 * size?2 * 1e4????????????MLE?????????
	 */
	class TableCombCalculator implements CombCalculator {
		long[][] table;
		int size;

		public TableCombCalculator(int size, long mod) {
			this.size = size;
			table = new long[size + 1][];

			table[0] = new long[1];
			table[0][0] = 1L;
			for (int n = 1; n <= size; n++) {
				table[n] = new long[n + 1];
				table[n][0] = 1L;
				for (int m = 1; m < n; m++) {
					table[n][m] = (table[n - 1][m - 1] + table[n - 1][m]) % mod;
				}
				table[n][n] = 1L;
			}
		}

		@Override
		public long comb(int n, int m) {
			if (n > size) {
				throw new RuntimeException("n is greater than size.");
			}
			if (n < 0 || m < 0 || n < m) {
				return 0L;
			}
			return table[n][m];
		}
	}

	interface Graph {
		void link(int from, int to, long cost);
		Optional<Long> getCost(int from, int to);
		int getVertexNum();
	}

	interface FlowResolver {
		long maxFlow(int from, int to);
	}

	/**
	 * ???????????
	 * ??????????????MLE?????
	 */
	class ArrayGraph implements Graph {
		private Long[][] costArray;
		private int vertexNum;

		public ArrayGraph(int n) {
			costArray = new Long[n][];
			for (int i = 0; i < n; i++) {
				costArray[i] = new Long[n];
			}
			vertexNum = n;
		}

		@Override
		public void link(int from, int to, long cost) {
			costArray[from][to] = new Long(cost);
		}

		@Override
		public Optional<Long> getCost(int from, int to) {
			return Optional.ofNullable(costArray[from][to]);
		}

		@Override
		public int getVertexNum() {
			return vertexNum;
		}
	}

	/**
	 * DFS(??????)?????
	 * ????O(E*MaxFlow)??? (E:???, MaxFlow:?????)
	 */
	class DfsFlowResolver implements FlowResolver {
		private Graph graph;
		public DfsFlowResolver(Graph graph) {
			this.graph = graph;
		}

		/**
		 * ?????(?????)????
		 * @param from ??(source)?ID
		 * @param to ??(target)?ID
		 * @return ?????(?????)
		 */
		public long maxFlow(int from, int to) {
			long sum = 0L;
			long currentFlow;
			do {
				currentFlow = flow(from, to, Long.MAX_VALUE / 3, new boolean[graph.getVertexNum()]);
				sum += currentFlow;
			} while (currentFlow > 0);
			return sum;
		}

		/**
		 * ?????? ?????????
		 * @param from ???????ID
		 * @param to ??(target)?ID
		 * @param current_flow ???????
		 * @param passed ?????????????????
		 * @return ??(target)??????/?????????
		 */
		private long flow(int from, int to, long current_flow, boolean[] passed) {
			passed[from] = true;
			if (from == to) {
				return current_flow;
			}
			for (int id = 0; id < graph.getVertexNum(); id++) {
				if (passed[id]) {
					continue;
				}
				Optional<Long> cost = graph.getCost(from, id);
				if (cost.orElse(0L) > 0) {
					long nextFlow = current_flow < cost.get() ? current_flow : cost.get();
					long returnFlow = flow(id, to, nextFlow, passed);
					if (returnFlow > 0) {
						graph.link(from, id, cost.get() - returnFlow);
						graph.link(id, from, graph.getCost(id, from).orElse(0L) + returnFlow);
						return returnFlow;
					}
				}
			}
			return 0L;
		}
	}

	/**
	 * 1-indexed?BIT??
	 */
	class BinaryIndexedTree {
		private long[] array;

		public BinaryIndexedTree(int size) {
			this.array = new long[size + 1];
		}

		/**
		 * ?????????????
		 * ????O(logN)
		 * @param index ?????????
		 * @param value ?????
		 */
		public void add(int index, long value) {
			for (int i = index; i < array.length; i += (i & -i)) {
				array[i] += value;
			}
		}

		/**
		 * 1????????????????
		 * ????O(logN)
		 * @param index ????????????
		 * @return 1?index????
		 */
		public long getSum(int index) {
			long sum = 0L;
			for (int i = index; i > 0; i -= (i & -i)) {
				sum += array[i];
			}
			return sum;
		}
	}

	/**
	 * 1-indexed?2??BIT??
	 */
	class BinaryIndexedTree2D {
		private long[][] array;

		public BinaryIndexedTree2D(int size1, int size2) {
			this.array = new long[size1 + 1][];
			for (int i = 1; i <= size1; i++) {
				this.array[i] = new long[size2 + 1];
			}
		}

		/**
		 * ?????????????
		 * ????O(logN * logN)
		 * @param index1 ???????1??????
		 * @param index2 ???????2??????
		 * @param value ?????
		 */
		public void add(int index1, int index2, long value) {
			for (int i1 = index1; i1 < array.length; i1 += (i1 & -i1)) {
				for (int i2 = index2; i2 < array.length; i2 += (i2 & -i2)) {
					array[i1][i2] += value;
				}
			}
		}

		/**
		 * (1,1)??????????????????
		 * ????O(logN * logN)
		 * @param index1 ??????????1??????
		 * @param index2 ??????????2??????
		 * @return (1,1)?(index1,index2)??????
		 */
		public long getSum(int index1, int index2) {
			long sum = 0L;
			for (int i1 = index1; i1 > 0; i1 -= (i1 & -i1)) {
				for (int i2 = index2; i2 > 0; i2 -= (i2 & -i2)) {
					sum += array[i1][i2];
				}
			}
			return sum;
		}
	}

	interface UnionFind {
		void union(int A, int B);
		boolean judge(int A, int B);
		Set<Integer> getSet(int id);
	}

	/**
	 * ArrayUnionFind???
	 * MapSet??????????????????????????????
	 * getSet?????O(logN * logN)?????????
	 * ???union?????2???????????????(????????????)
	 */
	class SetUnionFind extends ArrayUnionFind {
		Map<Integer, Set<Integer>> map;
		public SetUnionFind(int size) {
			super(size);
			map = new HashMap<>();
			for (int i = 0; i < size; i++) {
				map.put(i, new HashSet<>());
				map.get(i).add(i);
			}
		}

		@Override
		protected void unionTo(int source, int dest) {
			super.unionTo(source, dest);
			map.get(dest).addAll(map.get(source));
		}

		@Override
		public Set<Integer> getSet(int id) {
			return map.get(root(id));
		}
	}

	/**
	 * ?????UnionFind???
	 * getSet?????O(NlogN)???TLE???
	 */
	class ArrayUnionFind implements UnionFind {
		int[] parent;
		int[] rank;
		int size;
		public ArrayUnionFind(int size) {
			parent = new int[size];
			for (int i = 0; i < size; i++) {
				parent[i] = i;
			}
			rank = new int[size];
			this.size = size;
		}

		@Override
		public void union(int A, int B) {
			int rootA = root(A);
			int rootB = root(B);
			if (rootA != rootB) {
				if (rank[rootA] < rank[rootB]) {
					unionTo(rootA, rootB);
				} else {
					unionTo(rootB, rootA);
					if (rank[rootA] == rank[rootB]) {
						rank[rootA]++;
					}
				}
			}
		}

		protected void unionTo(int source, int dest) {
			parent[source] = dest;
		}

		@Override
		public boolean judge(int A, int B) {
			return root(A) == root(B);
		}

		@Override
		public Set<Integer> getSet(int id) {
			Set<Integer> set = new HashSet<>();
			IntStream.range(0, size).filter(i -> judge(i, id)).forEach(set::add);
			return set;
		}

		protected int root(int id) {
			if (parent[id] == id) {
				return id;
			}
			parent[id] = root(parent[id]);
			return parent[id];
		}
	}

	/**
	 * ??????????
	 */
	class PrimeNumberUtils {
		boolean[] isPrimeArray;
		List<Integer> primes;

		/**
		 * ???????????????????????????
		 * @param limit ???????(?????????????????)
		 */
		public PrimeNumberUtils(int limit) {
			if (limit > 10000000) {
				System.err.println("?????????????????????????TLE????????????");
			}
			primes = new ArrayList<>();
			isPrimeArray = new boolean[limit];
			if (limit > 2) {
				primes.add(2);
				isPrimeArray[2] = true;
			}

			for (int i = 3; i < limit; i += 2) {
				if (isPrime(i, primes)) {
					primes.add(i);
					isPrimeArray[i] = true;
				}
			}
		}

		public List<Integer> getPrimeNumberList() {
			return primes;
		}

		public boolean isPrime(int n) {
			return isPrimeArray[n];
		}

		private boolean isPrime(int n, List<Integer> primes) {
			for (int prime : primes) {
				if (n % prime == 0) {
					return false;
				}
				if (prime > Math.sqrt(n)) {
					break;
				}
			}
			return true;
		}
	}

	interface BitSet {
		void set(int index, boolean bit);
		boolean get(int index);
		void shiftRight(int num);
		void shiftLeft(int num);
		void or(BitSet bitset);
		void and(BitSet bitset);
	}

	/**
	 * Long??????BitSet???
	 * get/set?O(1)
	 * shift/or/and?O(size / 64)
	 */
	class LongBit implements BitSet {
		long[] bitArray;

		public LongBit(int size) {
			bitArray = new long[((size + 63) / 64)];
		}

		@Override
		public void set(int index, boolean bit) {
			int segment = index / 64;
			int inIndex = index % 64;
			if (bit) {
				bitArray[segment] |= 1L << inIndex;
			} else {
				bitArray[segment] &= ~(1L << inIndex);
			}
		}

		@Override
		public boolean get(int index) {
			int segment = index / 64;
			int inIndex = index % 64;
			return (bitArray[segment] & (1L << inIndex)) != 0L;
		}

		@Override
		public void shiftRight(int num) {
			int shiftSeg = num / 64;
			int shiftInI = num % 64;
			for (int segment = 0; segment < bitArray.length; segment++) {
				int sourceSeg = segment + shiftSeg;
				if (sourceSeg < bitArray.length) {
					bitArray[segment] = bitArray[sourceSeg] >>> shiftInI;
					if (shiftInI > 0 && sourceSeg + 1 < bitArray.length) {
						bitArray[segment] |= bitArray[sourceSeg + 1] << (64 - shiftInI);
					}
				} else {
					bitArray[segment] = 0L;
				}
			}
		}

		@Override
		public void shiftLeft(int num) {
			int shiftSeg = num / 64;
			int shiftInI = num % 64;
			for (int segment = bitArray.length - 1; segment >= 0; segment--) {
				int sourceSeg = segment - shiftSeg;
				if (sourceSeg >= 0) {
					bitArray[segment] = bitArray[sourceSeg] << shiftInI;
					if (shiftInI > 0 && sourceSeg > 0) {
						bitArray[segment] |= bitArray[sourceSeg - 1] >>> (64 - shiftInI);
					}
				} else {
					bitArray[segment] = 0L;
				}
			}
		}

		public long getLong(int segment) {
			return bitArray[segment];
		}

		@Override
		public void or(BitSet bitset) {
			if (!(bitset instanceof LongBit)) {
				return;
			}
			for (int segment = 0; segment < bitArray.length; segment++) {
				bitArray[segment] |= ((LongBit)bitset).getLong(segment);
			}
		}

		@Override
		public void and(BitSet bitset) {
			if (!(bitset instanceof LongBit)) {
				return;
			}
			for (int segment = 0; segment < bitArray.length; segment++) {
				bitArray[segment] &= ((LongBit)bitset).getLong(segment);
			}
		}
	}

}