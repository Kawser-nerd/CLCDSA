import java.util.*;

public class Main {
	public static void main(String[] args) {
		ValentinsDay valentins = new ValentinsDay();
		valentins.run();
	}
}

class ValentinsDay {
	
	int N;
	int M;
	int P;
	int Q;
	int R;
	Choco[] chocos;
	
	ValentinsDay() {
		//input;
		Scanner cin = new Scanner(System.in);
		this.N = cin.nextInt();
		this.M = cin.nextInt();
		this.P = cin.nextInt();
		this.Q = cin.nextInt();
		this.R = cin.nextInt();
		
		this.chocos = new Choco[R];
		for (int i = 0; i < R; i++) {
			int from = cin.nextInt() - 1;
			int to = cin.nextInt() - 1;
			int happiness = cin.nextInt();
			chocos[i] = new Choco(from, to, happiness);
		}
	}
	
	void run() {
		
		int maxHappiness = 0;
		
		//??bit???????
		for (int i = 0; i < 1 << N; i++) {
			
			if (flagCount(i) != P) 
				continue;
			
			int[] scores = new int[M];
			for (int j = 0; j < N; j++) {

				//????j??????????????
				if ((i >> j & 1) == 1) 
					getScores(j, scores);
				
			}
			
			Arrays.sort(scores);
							
			int tmpMax = getMaxScore(scores);
			maxHappiness = Math.max(maxHappiness, tmpMax);
		}
		
		System.out.println(maxHappiness);
	}
	
	int getMaxScore(int[] scores) {
		int max = 0;
		for (int i = M - 1; i >= M - Q; i--) {
			max += scores[i];
		}
		return max;
	}
	
	void getScores(int j, int[] scores) {
		for(Choco choco: chocos) {
			if (choco.from == j) {
				scores[choco.to] += choco.happiness;
			}
		}
	}
	
	int flagCount(int i) {
		int count = 0;
		for (int j = 0; j < N; j++) {
			if ((i >> j & 1) == 1) {
				count++;
			}
		}
		return count;
	}
	
	class Choco {
		
		int from;
		int to;
		int happiness;
		
		Choco(int from, int to, int happiness) {
			this.from = from;
			this.to = to;
			this.happiness = happiness;
		}
	}
}