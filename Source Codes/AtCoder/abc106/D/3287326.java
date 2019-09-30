import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeSet;

import org.omg.Messaging.SyncScopeHelper;

public class Main {
	Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		new Main();
	}
	public Main(){
		new ABC106().doIt();
	}
	class ABC106{
		void doIt(){
			int N = sc.nextInt();
			int M = sc.nextInt();
			int Q = sc.nextInt();
			int station[][] = new int[N+10][N+10];
			int cnt[][] = new int[N+10][N+10];
			for(int i = 0;i < M;i++) {
				int L = sc.nextInt();
				int R = sc.nextInt();
				station[L][R]++;
			}
			for(int i = N + 1;i >= 0;i--) {
				for(int j = 0;j < N+1;j++) {
					station[i][j] = station[i][j] + station[i+1][j];
				}
			}
			for(int i = N + 1;i >= 0;i--) {
				for(int j = 0;j < N+1;j++) {
					station[i][j+1] = station[i][j+1] + station[i][j];
				}
			}
			for(int i = 0;i < Q;i++) {
				int qs = sc.nextInt();
				int qg = sc.nextInt();
				System.out.println(station[qs][qg]);
			}
		}
	}
}