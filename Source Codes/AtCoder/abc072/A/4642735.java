import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
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
		new Test_100().doIt();
	}
	class Test_100{
		void doIt() {
			int X = sc.nextInt();
			int T = sc.nextInt();
			int ans = X - T;
			if(ans < 0)System.out.println(0);
			else System.out.println(ans);
		}
	}
}