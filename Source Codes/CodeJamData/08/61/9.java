import static java.lang.Math.*;
import static java.lang.System.in;
import static java.lang.System.out;
import java.util.*;
import static java.util.Arrays.*;
import java.math.*;
import static java.math.BigInteger.*;

public class A {
	final static int MAX = 10000000;
	public static void main(String[] main) {
		Scanner scin = new Scanner(in);
		int C = scin.nextInt();
		for (int z = 1; z <= C; ++z) {
			int N = scin.nextInt();
			Animal[] animals = new Animal[N];
			for (int i = 0; i < N; ++i) {
				Animal a = new Animal();
				a.h = scin.nextInt();
				a.w = scin.nextInt();
				a.bird = scin.next().equals("BIRD");
				if (!a.bird) scin.next();
				animals[i] = a;
			}
			int h_max = 0;
			int h_min = MAX;
			int w_max = 0;
			int w_min = MAX;
			for (Animal a : animals) {
				if (a.bird) {
					h_max = max(h_max, a.h);
					h_min = min(h_min, a.h);
					w_max = max(w_max, a.w);
					w_min = min(w_min, a.w);
				}
			}
			int h_up = MAX;
			int h_do = 0;
			int w_up = MAX;
			int w_do = 0;
			for (Animal a : animals) {
				if (!a.bird) {
					if (h_min <= a.h && a.h <= h_max) {
						if (a.w > w_max) {
							w_up = min(w_up, a.w);
						} else {
							w_do = max(w_do, a.w);
						}
					} else if (w_min <= a.w && a.w <= w_max) {
						if (a.h > h_max) {
							h_up = min(h_up, a.h);
						} else {
							h_do = max(h_do, a.h);
						}
					}
				}
			}
			for (Animal a : animals) {
				if (!a.bird) {
					if (a.h >= h_up || a.h <= h_do) {
						
					} else if (a.w >= w_up || a.w <= w_do) {
						
					}
				}
			}
			out.println("Case #" + z + ":");
			int M = scin.nextInt();
			while (M-- > 0) {
				int h = scin.nextInt();
				int w = scin.nextInt();
				if (h_min <= h && h <= h_max && w_min <= w && w <= w_max) {
					out.println("BIRD");
				} else if (h >= h_up || h <= h_do || w >= w_up || w <= w_do) {
					out.println("NOT BIRD");
				} else {
					out.println("UNKNOWN");
				}
			}
		}
	}
	
	static class Animal {
		boolean bird;
		int h;
		int w;
	}
}
