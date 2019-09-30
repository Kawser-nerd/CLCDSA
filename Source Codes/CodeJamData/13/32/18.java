import java.io.*;
import java.util.*;

public class Prob2 {
	public static void main(String[] args) throws Exception {
		PrintWriter pw = new PrintWriter(new FileWriter("out2.txt"));
		BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
		
		int nrTests = Integer.parseInt(br.readLine());
		for(int testNr = 1; testNr <= nrTests; testNr++) {
			String[] strs = br.readLine().split(" ");
			int x = Integer.parseInt(strs[0]), y = Integer.parseInt(strs[1]);
			
			int ax = Math.abs(x), ay = Math.abs(y);

			long sum = Math.abs(x) + Math.abs(y);
			long val = (int)Math.sqrt(2.0 * sum + 0.1);
			while(val * (val + 1) / 2 > sum) {
				val--;
			}
			while(val * (val + 1) / 2 < sum) {
				val++;
			}
			
			if(val * (val + 1) / 2 == sum) {
				int nv = (int)val;
				char[] chr = new char[nv];
				Arrays.fill(chr, 'X');
				while(ax > nv) {
					ax -= nv;
					nv--;
					chr[nv] = x > 0 ? 'E' : 'W';
				}
				if(ax > 0) {
					chr[ax - 1] = x > 0 ? 'E' : 'W';
				}
				for(int i = 0; i < chr.length; i++) {
					if(chr[i] == 'X') {
						chr[i] = y > 0 ? 'N' : 'S';
					}
				}
				pw.println("Case #" + testNr + ": " + new String(chr));
				continue;
			}
			
			long dif = (val * (val + 1) / 2) - sum;
			if(dif % 2 == 0) {
				int nv = (int)val, forb = (int)(dif / 2);
				char[] chr = new char[nv];
				Arrays.fill(chr, 'X');
				
				if(y == 0) {
					Arrays.fill(chr, x > 0 ? 'E' : 'W');
					chr[forb - 1] = x > 0 ? 'W' : 'E';
					pw.println("Case #" + testNr + ": " + new String(chr));
					continue;
				}
				
				if(nv == forb) {
					nv--;
				}
				while(ax > nv) {
					ax -= nv;
					nv--;
					chr[nv] = x > 0 ? 'E' : 'W';
					if(nv == forb) {
						nv--;
					}
				}
				if(ax > 0) {
					if(ax != forb) {
						chr[ax - 1] = x > 0 ? 'E' : 'W';
					} else {
						if(ax > 2) {
							chr[ax - 2] = chr[0] = x > 0 ? 'E' : 'W';
						} else {
							System.out.println("ERROR: ax = 1");
						}
					}
				}
				
				chr[forb - 1] = y > 0 ? 'S' : 'N';
				for(int i = 0; i < chr.length; i++) {
					if(chr[i] == 'X') {
						chr[i] = y > 0 ? 'N' : 'S';
					}
				}
				pw.println("Case #" + testNr + ": " + new String(chr));
				continue;
			} else if(val % 2 == 0) {
				dif += val + 1;
				int nv = (int)val + 1, forb = (int)(dif / 2);
				char[] chr = new char[nv];
				Arrays.fill(chr, 'X');
				
				if(y == 0) {
					Arrays.fill(chr, x > 0 ? 'E' : 'W');
					chr[forb - 1] = x > 0 ? 'W' : 'E';
					pw.println("Case #" + testNr + ": " + new String(chr));
					continue;
				}
				
				if(nv == forb) {
					nv--;
				}
				while(ax > nv) {
					ax -= nv;
					nv--;
					chr[nv] = x > 0 ? 'E' : 'W';
					if(nv == forb) {
						nv--;
					}
				}
				if(ax > 0) {
					if(ax != forb) {
						chr[ax - 1] = x > 0 ? 'E' : 'W';
					} else {
						if(ax > 2) {
							chr[ax - 2] = chr[0] = x > 0 ? 'E' : 'W';
						} else {
							System.out.println("ERROR: ax = 1");
						}
					}
				}
				
				chr[forb - 1] = y > 0 ? 'S' : 'N';
				for(int i = 0; i < chr.length; i++) {
					if(chr[i] == 'X') {
						chr[i] = y > 0 ? 'N' : 'S';
					}
				}
				pw.println("Case #" + testNr + ": " + new String(chr));
				continue;
			} else {
				dif += val + 1 + val + 2;
				int nv = (int)val + 2, forb = (int)(dif / 2), forb1 = forb / 3, forb2 = forb - forb1;
				char[] chr = new char[nv];
				Arrays.fill(chr, 'X');
				
				if(y == 0) {
					Arrays.fill(chr, x > 0 ? 'E' : 'W');
					chr[forb1 - 1] = chr[forb2 - 1] = x > 0 ? 'W' : 'E';
					pw.println("Case #" + testNr + ": " + new String(chr));
					continue;
				}
				
				if(nv == forb1 || nv == forb2) {
					nv--;
				}
				while(ax > nv) {
					ax -= nv;
					nv--;
					chr[nv] = x > 0 ? 'E' : 'W';
					if(nv == forb1 || nv == forb2) {
						nv--;
					}
				}
				if(ax > 0) {
					if(ax != forb1 && ax != forb2) {
						chr[ax - 1] = x > 0 ? 'E' : 'W';
					} else {
						if(ax > 2 && ax - 1 != forb1 && ax - 1 != forb2 && forb1 != 1) {
							chr[ax - 2] = chr[0] = x > 0 ? 'E' : 'W';
						} else {
							if(forb1 > 0 && forb2 < chr.length && chr[forb1 - 2] == 'X' && chr[forb2] == 'X') {
								forb1--;
								forb2++;
								chr[ax - 1] = x > 0 ? 'E' : 'W';
							} else {
								System.out.println("ERROR: ax = 1 testNr = " + testNr);
							}
						}
					}
				}
				
				chr[forb1 - 1] = chr[forb2 - 1] = y > 0 ? 'S' : 'N';
				for(int i = 0; i < chr.length; i++) {
					if(chr[i] == 'X') {
						chr[i] = y > 0 ? 'N' : 'S';
					}
				}
				pw.println("Case #" + testNr + ": " + new String(chr));
				continue;
			}
		}
		
		br.close();
		pw.close();
	}
}
