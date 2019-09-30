import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner io = new Scanner(System.in);
		int N = io.nextInt();
		long[] ans = new long[N];
		PriorityQueue<Deck> que = new PriorityQueue<>();
		for(int i=1;i<=N;i++){
			que.add(new Deck(i,io.nextInt()));
		}
		que.add(new Deck(0,0));
/*		for (int i = 0; i < N; i++) {
			System.out.println(que.peek().NO+" "+que.poll().num);
		}
*/
		Deck nowDeck;
		int nowNO = Integer.MAX_VALUE;
		int nowNum;
		for(int i=1;i<=N;i++){
			nowDeck = que.poll();
			nowNO = Math.min(nowNO,nowDeck.NO);
			ans[nowNO-1] += (long)(nowDeck.num-que.peek().num)*i;
		}
		for(int i=0;i<N;i++){
			System.out.println(ans[i]);
		}
	}
}

class Deck implements Comparable<Deck>{
	int NO;
	int num;
	public Deck(int NO, int num){
		this.NO = NO;
		this.num = num;
	}
	@Override
	public int compareTo(Deck o) {
		return (o.num-num==0)? o.NO-NO
							  :o.num-num;
	}
	
}