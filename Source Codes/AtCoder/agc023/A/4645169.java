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
			int N = sc.nextInt();
			long S[] = new long[N+1];
			S[0] = 0;
			for(int i = 1;i < N+1;i++) {
				S[i] = S[i-1] + sc.nextLong();
			}
			Arrays.sort(S);
			long ans = 0;
			long cnt = 0;
			for(int i = 1;i < N+1;i++) {
				if(S[i] == S[i-1]) {
					cnt++;
					ans = ans + cnt;
				}
				else cnt = 0;
			}
			System.out.println(ans);
		}
	}
}