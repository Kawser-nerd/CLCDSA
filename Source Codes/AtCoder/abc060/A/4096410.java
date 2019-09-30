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
			String strA = sc.next();
			String strB = sc.next();
			String strC = sc.next();
			int A = strA.length();
			int B = strB.length();
			int C = strC.length();
			if(strA.substring(A-1, A).equals(strB.substring(0, 1))) {
				if(strB.substring(B-1,B).equals(strC.substring(0, 1))) {
					System.out.println("YES");
				}else {
					System.out.println("NO");
				}
			}else {
				System.out.println("NO");
			}
		}
	}
}