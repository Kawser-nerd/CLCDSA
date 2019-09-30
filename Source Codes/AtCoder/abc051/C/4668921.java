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
			int sx = sc.nextInt();
			int sy = sc.nextInt();
			int tx = sc.nextInt();
			int ty = sc.nextInt();
			Pos p1 = new Pos(tx - sx,ty - sy); //"RU"
			Pos p2 = new Pos(tx - sx,ty - sy); //"LD"
			Pos p3 = new Pos(tx - sx + 1,ty - sy + 1); //"LD"
			Pos p4 = new Pos(tx - sx + 1,ty - sy + 1); //"RU"
			
			for(int i = 0;i < p1.y;i++)System.out.print("U");
			for(int i = 0;i < p1.x;i++)System.out.print("R");
			
			for(int i = 0;i < p2.y;i++)System.out.print("D");
			for(int i = 0;i < p2.x;i++)System.out.print("L");
			
			System.out.print("L");
			for(int i = 0;i < p3.y;i++)System.out.print("U");
			for(int i = 0;i < p3.x;i++)System.out.print("R");
			System.out.print("D");
			
			System.out.print("R");
			for(int i = 0;i < p4.y;i++)System.out.print("D");
			for(int i = 0;i < p4.x;i++)System.out.print("L");
			System.out.println("U");
		}
	}
	class Pos{
		int x;
		int y;
		public Pos(int x,int y) {
			this.x = x;
			this.y = y;
		}
	}
}