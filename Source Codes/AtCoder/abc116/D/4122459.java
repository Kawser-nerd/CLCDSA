import java.util.Collections;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = Integer.parseInt(scan.next());
		int K = Integer.parseInt(scan.next());
		int[] t = new int[N];
		long[] d = new long[N];
		Sushi sushi = null;
		Set<Integer> kindSet = new HashSet<>();
		PriorityQueue<Sushi> sushiQueue = new PriorityQueue<>(Collections.reverseOrder());
		for (int i = 0; i < N; i++) {
			sushi = new Sushi(Integer.parseInt(scan.next()), Integer.parseInt(scan.next()));
			sushiQueue.add(sushi);
			kindSet.add(sushi.getT());
		}

		int maxKind = kindSet.size();

		SushiList S = new SushiList(N);
		//K????????S???
		for (int i = 0; i < K; i++) {
			S.add(sushiQueue.poll());
		}

		if (S.getKindNum() == maxKind) { //????????????????
			System.out.println(S.getScore());
			return;
		}

		long max = S.getScore();
		for (int i = S.getKindNum(); i <= maxKind; i++) {
			if (S.getMinSushi() == null) {
				System.out.println(Math.max(max, S.score));
				return;
			}
			S.removeMinSushi();
			while (!sushiQueue.isEmpty()) {
				if(S.sushiArray[sushiQueue.peek().getT()].isEmpty()) {
					S.add(sushiQueue.poll());
					break;
				} else {
					sushiQueue.poll();
				}
			}
			max = Math.max(max, S.score);
		}
		System.out.println(max);
	}

	public static class SushiList {
		private int N;
		private int kindNum; //???
		private long score;
		private Sushi minSushi;
		private PriorityQueue<Sushi>[] sushiArray; //??????????
		private PriorityQueue<Sushi> sushiQueue; // remove???????

		public SushiList(int N) {
			this.N = N;
			int kindNum = 0;
			score = 0;
			minSushi = null;
			sushiArray = new PriorityQueue[N + 1];
			sushiQueue = new PriorityQueue<>();
			for (int i = 0; i < N + 1; i++) {
				sushiArray[i] = new PriorityQueue<Sushi>();
			}
		}

		public void add(Sushi sushi) {
			sushiArray[sushi.getT()].add(sushi);
			if (sushiArray[sushi.getT()].size() > 1) {
				if (minSushi == null) { //??????????
					minSushi = sushiArray[sushi.getT()].peek();
				} else {
					if (minSushi.getD() > sushiArray[sushi.getT()].peek().getD()) {
						minSushi = sushi;
					}
				}
			}
			sushiQueue.add(sushi);
			score += sushi.getD();
			if (sushiArray[sushi.getT()].size() == 1) {
				score += kindNum * 2 + 1; //p????p+1??????????????
				kindNum++;
			}
		}

		public void removeMinSushi() {
			score -= minSushi.getD();
			sushiArray[minSushi.getT()].poll();
			//minSushi???
			Sushi preMinSushi = minSushi;
			minSushi = null;
			while (!sushiQueue.isEmpty()) {
				if (preMinSushi!=sushiQueue.peek() && sushiArray[sushiQueue.peek().getT()].size() > 1) {
					minSushi = sushiQueue.poll();
					break;
				} else {
					sushiQueue.poll();
				}
			}
		}

		public Sushi getMinSushi() {
			return minSushi;
		}

		public void setMinSushi(Sushi minSushi) {
			this.minSushi = minSushi;
		}

		public long getScore() {
			return score;
		}

		public void setScore(int score) {
			this.score = score;
		}

		public int getKindNum() {
			return kindNum;
		}

		public void setKindNum(int kindNum) {
			this.kindNum = kindNum;
		}
	}

	public static class Sushi implements Comparable<Sushi> {
		private int t;
		private long d;

		public Sushi(int t, long d) {
			this.t = t;
			this.d = d;
		}

		public boolean isSameType(Sushi s) {
			return this.t == s.getT();
		}

		public int getT() {
			return t;
		}

		public void setT(int t) {
			this.t = t;
		}

		public long getD() {
			return d;
		}

		public void setD(long d) {
			this.d = d;
		}

		@Override
		public int compareTo(Sushi other) {
			return (int)(this.d - other.d);
		}

	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.