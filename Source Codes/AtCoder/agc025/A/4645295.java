import java.net.StandardSocketOptions;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeSet;

import org.omg.Messaging.SyncScopeHelper;
import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

public class Main {
	Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		new Main();
	}
	public Main(){
		new Test_200().doIt();
	}
	class Test_200{
		void doIt() {
			int Wa[] = new int[100001];
			Pa_10(Wa);
			int ans = Integer.MAX_VALUE;
			int N = sc.nextInt();
			for(int i = 1;i <= N/2;i++) {
				ans = Math.min(ans, Wa[N - i] + Wa[i]);
			}
			System.out.println(ans);
		}
		void Pa_10(int Wa[]){
			for(int i = 0;i <= 100000;i++) {
				Wa[i] = i % 10;
				Wa[i] = Wa[i] + ((i / 10) % 10);
				Wa[i] = Wa[i] + ((i / 100) % 10);
				Wa[i] = Wa[i] + ((i / 1000) % 10);
				Wa[i] = Wa[i] + ((i / 10000) % 10);
				Wa[i] = Wa[i] + ((i / 100000) % 10);
			}
		}
	}
}