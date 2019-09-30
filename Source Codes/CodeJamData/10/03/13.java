import java.io.*;
import java.util.*;

public class Park {
	
	static Scanner in;
	static PrintWriter out;
	
	public static void main(String[] args) throws Exception {
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter(new File("output.txt"));

		int C = in.nextInt();
		for (int cas=1; cas<=C; cas++) {
		
			long ans = 0;

			int r = in.nextInt();
			int k = in.nextInt();
			int n = in.nextInt();
			int[] g = new int[n];
			
			long sum = 0;
			
			for (int i=0; i<n; i++) {
				g[i] = in.nextInt();
				sum += g[i];
			}

			if (sum <= k) {
				ans = sum * (long)r;
			} else {
				
				sum = 0;
				
				long[] use = new long[n];
				int[] step = new int[n];

				int st = 0;

				Arrays.fill(use, -1);
				int uk = 0;
				while (st < r && use[uk] == -1) {
					use[uk] = sum;
					step[uk] = st++;
					long locsum = 0;
					while (locsum + g[uk] <= k) {
						locsum += g[uk++];
						uk %= n; 
					}
					sum += locsum;
				}
                
                if (st == r) {
                	ans = sum;
                } else {
                	
                	ans = sum;

                	long lsum = sum - use[uk];
                	int shagov = st - step[uk];
                	r -= st;
                	int raz = r / shagov;
                    ans += raz * (long) lsum;
                    r -= raz * shagov; 

                    System.out.println("DOSHEL");

                    while (r > 0) {
						r--;
						long locsum = 0;
						while (locsum + g[uk] <= k) {
							locsum += g[uk++];
							uk %= n; 
						}
						ans += locsum;
					}

                }
			}

			out.printf("Case #%d: %d%n", cas, ans);
		}

		out.close();	
	}
}