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
			int a = sc.nextInt();
			int b = sc.nextInt();
			int ans = (b - a) % 2;
			if(a <= 0 && b >= 0)System.out.println("Zero");
			else if(a > 0 && b > 0)System.out.println("Positive");
			else if(ans == 0)System.out.println("Negative");
			else System.out.println("Positive");
		}
	}
}