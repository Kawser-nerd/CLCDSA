package onsite;

import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		a:for(int CASE = 1, N = sc.nextInt(); CASE <= N; CASE++) {
			
			System.out.printf("Case #%d:\n", CASE);
			int n = sc.nextInt();
			int minBX = 1000000, maxBX = -1, minBY = 1000000, maxBY = -1;
			List<Not> No = new ArrayList<Not>();
			int birds = 0;
			for(int i = 0; i < n; i++) {
				int x = sc.nextInt(), y = sc.nextInt();
				if(sc.nextLine().equals(" BIRD")) {
					minBX = Math.min(minBX, x);
					maxBX = Math.max(maxBX, x);
					minBY = Math.min(minBY, y);
					maxBY = Math.max(maxBY, y);
					birds++;
				} else {
//					minNBX = Math.min(minNBX, x);
//					maxNBX = Math.max(maxNBX, x);
//					minNBY = Math.min(minNBY, y);
//					maxNBY = Math.max(maxNBY, y);
					No.add(new Not(x, y));
				}
			}
//			System.out.println(birds);
			List<List<Not>> Nos = new ArrayList<List<Not>>();
			for(int i = 0; i < 8; i++) {
				Nos.add(new ArrayList<Not>());
			}
			for(Not no : No) {
				if(no.x <= minBX && no.y <= minBY) {
					Nos.get(0).add(no);
				}
				if(no.x >= minBX && no.x <= maxBX && no.y <= minBY) {
					Nos.get(1).add(no);
				}
				if(no.x >= maxBX && no.y <= minBY) {
					Nos.get(2).add(no);
				}
				if(no.y >= minBY && no.y <= maxBY && no.x <= minBX) {
					Nos.get(3).add(no);
				}
				if(no.y >= minBY && no.y <= maxBY && no.x >= maxBX) {
					Nos.get(4).add(no);
				}
				if(no.x <= minBX && no.y >= maxBY) {
					Nos.get(5).add(no);
				}
				if(no.x >= minBX && no.x <= maxBX && no.y >= maxBY) {
					Nos.get(6).add(no);
				}
				if(no.x >= maxBX && no.y >= maxBY) {
					Nos.get(7).add(no);
				}
			}
			
//			System.out.println(minBX+" "+maxBX+" "+minBY+" "+maxBY);
//			for(int i = 0; i < 8; i++) {
//				System.out.println(i+":"+Nos.get(i).size());
//				for(Not no : Nos.get(i)) {
//					System.out.println(no);
//				}
//			}
			
			
			int m = sc.nextInt();
			b:for(int i = 0; i < m; i++) {
				int x = sc.nextInt(), y = sc.nextInt();
//				System.out.println(x+" "+y);
				if(birds == 0) {
					for(Not no : No) {
						if(x == no.x && y == no.y) {
							System.out.println("NOT BIRD");
						}
					}
					System.out.println("UNKNOWN");
					continue;
				}
				if(minBX <= x && x <= maxBX && minBY <= y && y <= maxBY) {
					System.out.println("BIRD");
					continue;
				}
				if(x <= minBX && y <= minBY) {
					for(Not no : Nos.get(0)) {
						if(x <= no.x && y <= no.y) {
							out();
							continue b;
						}
					}
				}
				if(x >= minBX) {
					for(Not no : Nos.get(1)) {
						if(y <= no.y) {
							out();
							continue b;
						}
					}
				}
				if(x >= maxBX && y <= minBY) {
					for(Not no : Nos.get(2)) {
						if(x >= no.x && y <= no.y) {
							out();
							continue b;
						}
					}
				}
				if(x <= minBX) {
//					Nos.get(3).add(no);
					for(Not no : Nos.get(3)) {
						if(x <= no.x) {
							out();
							continue b;
						}
					}
				}
				if(x >= maxBX) {
//					Nos.get(4).add(no);
					for(Not no : Nos.get(4)) {
						if(x >= no.x) {
							out();
							continue b;
						}
					}
				}
				if(x <= minBX && y >= maxBY) {
//					Nos.get(5).add(no);
//					System.out.println(x+" "+y);
					for(Not no : Nos.get(5)) {
						if(x <= no.x && y >= no.y) {
							out();
							continue b;
						}
					}
				}
				if(y >= maxBY) {
//					Nos.get(6).add(no);
//					System.out.println(x+" "+y+" "+Nos.get(6).size());
					for(Not no : Nos.get(6)) {
						if(y >= no.y) {
							out();
							continue b;
						}
					}
				}
				if(x >= maxBX && y >= maxBY) {
//					Nos.get(7).add(no);
					for(Not no : Nos.get(7)) {
						if(x >= no.x && y >= no.y) {
							out();
							continue b;
						}
					}
				}
				
				System.out.println("UNKNOWN");
			}
		}
	}
	
	void out() {
		System.out.println("NOT BIRD");
	}
	
	static class Not implements Comparable<Not> {
		public Not(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		int x, y;

		public int compareTo(Not o) {
			return x != o.x ? x - o.x : y - o.y;
		}
		
		public String toString() {
			return "("+x+", "+y+")";
		}
	}
}