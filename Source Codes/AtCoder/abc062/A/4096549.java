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
			int index[] = new int[13];
			index[1] = index[3] = index[5] = index[7] = index[8] = index[10] = index [12] = 1;
			index[4] = index[6] = index[9] = index[11] = 2;
			index[2] = 3;
			int x = sc.nextInt();
			int y = sc.nextInt();
			if(index[x] == index[y])System.out.println("Yes");
			else System.out.println("No");
		}
	}
}