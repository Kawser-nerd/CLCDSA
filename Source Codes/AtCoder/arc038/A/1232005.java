import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		int n=s.nextInt(),sum=0;
		PriorityQueue<Integer> que=new PriorityQueue<>(Comparator.reverseOrder());
		for(int i=0;i<n;i++) que.add(s.nextInt());

		for(int i=0;!que.isEmpty();i++)
			if(i%2==0) sum+=que.poll();
			else que.poll();

		System.out.println(sum);
	}
}