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
		new Test_300().doIt();
	}
	class Test_300{
		void doIt() {
			int N = sc.nextInt();
			long K = sc.nextLong();
			long A[] = new long[100002];
			for(int i = 0;i < N;i++) {
				int a = sc.nextInt();
				long b = sc.nextLong();
				A[a] = A[a] + b;
			}
			long cnt = 0;
			for(int i = 0;i < 100002;i++) {
				cnt = cnt + A[i];
				if(cnt >= K) {
					System.out.println(i);
					break;
				}
			}
		}
	}
}