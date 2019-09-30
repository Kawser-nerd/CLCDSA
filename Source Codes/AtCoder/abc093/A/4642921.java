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
			String str = sc.next();
			 int a = 0;
			 int b = 0;
			 int c = 0;
			 for(int i = 0;i < str.length();i++) {
				 char ch = str.charAt(i);
				 if(ch == 'a')a = 1;
				 else if(ch == 'b')b = 1;
				 else if(ch == 'c')c = 1;
			 }
			 int ans = a + b + c;
			 if(ans == 3)System.out.println("Yes");
			 else System.out.println("No");
		}
	}
}