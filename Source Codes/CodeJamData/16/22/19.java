package r1b2016;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("B.out"));
		
		for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			String[] s = in.nextLine().split(" +");
			char[] a = s[0].toCharArray();
			char[] b = s[1].toCharArray();
			int n = a.length;
			
			int p = -1;
			for (int i = 0; i < n && p == -1; i++) {
				if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) {
					p = i;
				}
			}
			
			if (p == -1) {
				for (int i = 0; i < n; i++) {
					if (a[i] == '?' && b[i] == '?') {
						a[i] = b[i] = '0';
					} else if (a[i] == '?') {
						a[i] = b[i];
					} else if (b[i] == '?') {
						b[i] = a[i];
					}
				}
				out.println(String.valueOf(a) + " " + String.valueOf(b));
				continue;
			}
			
			int q = -1;
			for (int i = p-1; i >= 0 && q == -1; i--) {
				if (a[i] == '?' || b[i] == '?') {
					q = i;
				}
			}
			
			if (q == -1) {
				boolean gr = a[p] > b[p];
				for (int i = 0; i < n; i++) {
					if (a[i] == '?') {
						a[i] = gr ? '0' : '9';
					}
					if (b[i] == '?') {
						b[i] = gr ? '9' : '0';
					}
				}
				out.println(String.valueOf(a) + " " + String.valueOf(b));
				continue;
			}
			
			boolean gr = a[p] > b[p];
			
			char[] c1 = Arrays.copyOf(a, n);
			char[] d1 = Arrays.copyOf(b, n);
			trySolve(c1, d1, p, gr);
			long ans1 = Math.abs(getLong(c1) - getLong(d1));
			
			for (int i = q; i >= 0; i--) {
				if (a[i] != '?' && b[i] != '?') {
					continue;
				}
				char[] c2 = Arrays.copyOf(a, n);
				char[] d2 = Arrays.copyOf(b, n);
				if (gr) {
					if (c2[i] == '9' || d2[i] == '0') {
						continue;
					}
					if (c2[i] == '?' && d2[i] == '?') {
						c2[i] = '0';
						d2[i] = '1';
					} else if (c2[i] == '?') {
						c2[i] = (char)(d2[i] - 1);
					} else if (d2[i] == '?') {
						d2[i] = (char)(c2[i] + 1);
					}
				} else {
					if (c2[i] == '0' || d2[i] == '9') {
						continue;
					}
					if (c2[i] == '?' && d2[i] == '?') {
						c2[i] = '1';
						d2[i] = '0';
					} else if (c2[i] == '?') {
						c2[i] = (char)(d2[i] + 1);
					} else if (d2[i] == '?') {
						d2[i] = (char)(c2[i] - 1);
					}
				}
				trySolve(c2, d2, i, !gr);
				long ans2 = Math.abs(getLong(c2) - getLong(d2));
				if (ans2 < ans1) {
					c1 = c2;
					d1 = d2;
					ans1 = ans2;
				} else if (ans2 == ans1) {
					if (getLong(c2) < getLong(c1)) {
						c1 = c2;
						d1 = d2;
						ans1 = ans2;
					} else if (getLong(c2) == getLong(c1)) {
						if (getLong(d2) < getLong(d1)) {
							c1 = c2;
							d1 = d2;
							ans1 = ans2;
						}
					}
				}
			}
			
			out.println(String.valueOf(c1) + " " + String.valueOf(d1));
		}

		out.flush();
	}

	static boolean match(int a, String s) {
		for (int i = s.length()-1; i >= 0; i--) {
			int d = a%10;
			a /= 10;
			if (s.charAt(i) != '?' && s.charAt(i) != d + '0') {
				return false;
			}
		}
		return true;
	}
	
	static void trySolve(char[] a, char[] b, int p, boolean gr) {
		for (int i = 0; i < p; i++) {
			if (a[i] == '?' && b[i] == '?') {
				a[i] = b[i] = '0';
			} else if (a[i] == '?') {
				a[i] = b[i];
			} else if (b[i] == '?') {
				b[i] = a[i];
			}
		}
		for (int i = p+1; i < a.length; i++) {
			if (a[i] == '?') {
				a[i] = gr ? '0' : '9';
			}
			if (b[i] == '?') {
				b[i] = gr ? '9' : '0';
			}
		}
	}
	
	static long getLong(char[] c) {
		return Long.valueOf(String.valueOf(c));
	}
}
