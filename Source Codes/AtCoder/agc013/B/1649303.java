import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}
	
	void solve() {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		boolean[]used=new boolean[n];
		Arrays.fill(used, false);
		ArrayList<Integer>[]path=new ArrayList[n];
		for(int i=0;i<n;i++) {
			path[i]=new ArrayList<Integer>();
		}
		int[]a=new int[m];
		int[]b=new int[m];
		for(int i=0;i<m;i++) {
			a[i]=sc.nextInt()-1;
			b[i]=sc.nextInt()-1;
			path[a[i]].add(b[i]);
			path[b[i]].add(a[i]);
		}
		Queue<Integer>ans1=new LinkedList<Integer>();
		Stack<Integer>ans2=new Stack<Integer>();
		int start=0;
		used[start]=true;
		ans1.add(start);
		int end1=start;
		int end2=path[end1].get(0);
		used[end2]=true;
		ans1.add(end2);
		
		while(true) {
			int next=-1;
			for(int i=0;i<path[end2].size();i++) {
				if(!used[path[end2].get(i)]) {
					next=path[end2].get(i);
					ans1.add(next);
					used[next]=true;
					end2=next;
					break;
				}
			}
			if(next==-1)break;
		}
		while(true) {
			int next=-1;
			for(int i=0;i<path[end1].size();i++) {
				if(!used[path[end1].get(i)]) {
					next=path[end1].get(i);
					ans2.push(next);
					used[next]=true;
					end1=next;
					break;
				}
			}
			if(next==-1)break;
		}
		System.out.println(ans1.size()+ans2.size());
		while(!ans2.isEmpty()) {
			System.out.print(ans2.pop()+1);
			if(!ans2.isEmpty())System.out.print(" ");
			else if(!ans1.isEmpty())System.out.print(" ");
		}
		while(!ans1.isEmpty()) {
			System.out.print(ans1.poll()+1);
			if(!ans1.isEmpty())System.out.print(" ");
		}
		System.out.println();
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.