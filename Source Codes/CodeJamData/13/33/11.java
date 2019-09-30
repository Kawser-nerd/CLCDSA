import java.io.*;
import java.util.*;

public class Prob3 {
	public static void main(String[] args) throws Exception {
		long time1 = System.currentTimeMillis();
		
		PrintWriter pw = new PrintWriter(new FileWriter("out3.txt"));
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
		
		int nrTests = Integer.parseInt(br.readLine());
		for(int testNr = 1; testNr <= nrTests; testNr++) {
			int n = Integer.parseInt(br.readLine());
			int[] ds = new int[n], ns = new int[n], ws = new int[n], es = new int[n], ss = new int[n], delta_ds = new int[n], delta_ps = new int[n], delta_ss = new int[n];
			for(int i = 0; i < n; i++) {
				String[] strs = br.readLine().split(" ");
				ds[i] = Integer.parseInt(strs[0]);
				ns[i] = Integer.parseInt(strs[1]);
				ws[i] = Integer.parseInt(strs[2]);
				es[i] = Integer.parseInt(strs[3]);
				ss[i] = Integer.parseInt(strs[4]);
				delta_ds[i] = Integer.parseInt(strs[5]);
				delta_ps[i] = Integer.parseInt(strs[6]);
				delta_ss[i] = Integer.parseInt(strs[7]);
			}
			int[] dayNr = new int[n];
			int res = 0;
			int[] wall = new int[1000];
			boolean vb = true;
			while(vb) {
				vb = false;
				int minDay = Integer.MAX_VALUE;
				for(int i = 0; i < n; i++) {
					if(dayNr[i] < ns[i]) {
						vb = true;
						minDay = Math.min(minDay, ds[i] + delta_ds[i] * dayNr[i]);
					}
				}
				if(minDay == Integer.MAX_VALUE) {
					break;
				}
				
				for(int i = 0; i < n; i++) {
					if(dayNr[i] < ns[i] && minDay == ds[i] + delta_ds[i] * dayNr[i]) {
						int posW = ws[i] + delta_ps[i] * dayNr[i];
						int posE = es[i] + delta_ps[i] * dayNr[i];
						int newS = ss[i] + delta_ss[i] * dayNr[i];
						for(int j = posW; j < posE; j++) {
							if(wall[j + 500] < newS) {
								res++;
								break;
							}
						}
					}
				}
				// update the wall
				for(int i = 0; i < n; i++) {
					if(dayNr[i] < ns[i] && minDay == ds[i] + delta_ds[i] * dayNr[i]) {
						int posW = ws[i] + delta_ps[i] * dayNr[i];
						int posE = es[i] + delta_ps[i] * dayNr[i];
						int newS = ss[i] + delta_ss[i] * dayNr[i];
						for(int j = posW; j < posE; j++) {
							if(wall[j + 500] < newS) {
								wall[j + 500] = newS;
							}
						}
						dayNr[i]++;
					}
				}
			}

			pw.println("Case #" + testNr + ": " + res);
		}
		
		br.close();
		pw.close();
	}
}

class Node {
	MyBits myBits = null;
	Node prev = null;
	int val = 0;
	
	public Node(int n, int val) {
		this.myBits = new MyBits(n, val);
		this.val = val;
	}
	
	public Node(MyBits myBits, Node prev, int val) {
		this.myBits = myBits;
		this.prev = prev;
		this.val = val;
	}
	
	boolean contains(int v) {
		return (myBits.bits[v >> 5] & (1 << (v & 31))) != 0;
	}
}

class MyBits {
	int[] bits = null;
	
	public MyBits(int n, int val) {
		this.bits = new int[(n - 1) / 32 + 1];
		this.bits[val >> 5] |= (1 << (val & 31));
	}
	
	public MyBits(MyBits prev, int val) {
		this.bits = new int[prev.bits.length];
		System.arraycopy(prev.bits, 0, this.bits, 0, bits.length);
		this.bits[val >> 5] |= (1 << (val & 31));
	}
	
	@Override
	public int hashCode() {
		switch(bits.length) {
			case 1: return bits[0];
			case 2: return (bits[0] & 1023) * (bits[1] & 1023);
			case 3: return (bits[0] & 1023) * (bits[1] & 1023) * (bits[2] & 1023);
			case 4: return (bits[0] & 255) * (bits[1] & 255) * (bits[2] & 255) * (bits[3] & 255);
			case 5: return (bits[0] & 255) * (bits[1] & 255) * (bits[2] & 255) * (bits[3] & 255);
			case 6: return (bits[0] & 255) * (bits[1] & 255) * (bits[2] & 255) * (bits[3] & 255);
			case 7: return (bits[0] & 255) * (bits[1] & 255) * (bits[2] & 255) * (bits[3] & 255);
		}
		return bits[0] % 1001;
	}
	
	@Override
	public boolean equals(Object obj) {
		MyBits nb = (MyBits)obj;
		
		if(bits.length != nb.bits.length) {
			return false;
		}
		for(int i = 0; i < bits.length; i++) {
			if(bits[i] != nb.bits[i]) {
				return false;
			}
		}
		return true;
	}
}