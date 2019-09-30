import java.util.HashMap;
import java.util.Map;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class CodeJamB {

	static int itemlen = 0;
	
	static class Index {
		int a;
		int b;
		int c;
		int d;
		
		Index() {
		}
		
		Index(Index that) {
			a = that.a;
			b = that.b;
			c = that.c;
			d = that.d;
		}
		Index(Index that, Index add) {
			set(that, add);
		}
		
		void set(Index that, Index add) {
			a = that.a + add.a;
			b = that.b + add.b;
			c = that.c + add.c;
			d = that.d + add.d;
		}
		int get() {
			int r = 1;
			if (itemlen >= 1) r = r * a % 10009;
			if (itemlen >= 2) r = r * b % 10009;
			if (itemlen >= 3) r = r * c % 10009;
			if (itemlen >= 4) r = r * d % 10009;
			return r;
		}
		
		Index(int[] current) {
			if (current.length >= 1) a = current[0];
			if (current.length >= 2) b = current[1];
			if (current.length >= 3) c = current[2];
			if (current.length >= 4) d = current[3];
		}
		public int hashCode() {
			return ((a * 13 + b) * 13 + c) * 13 + d; 
		}
		public boolean equals(Object t) {
			Index that = (Index)t;
			return this.a == that.a && this.b == that.b 
				&& this.c == that.c && this.d == that.d;
		}
	}
	
	static class VInt {
		int v;
		VInt() {
			v = 0;
		}
		VInt(int v) {
			this.v = v;
		}
	}
	
	public static void main(String[] args) {
		
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			String line = in.readLine();
			int total = Integer.valueOf(line);
			for (int casen=1; casen <= total; casen++) {
				System.out.print("Case #" + casen + ":");
				
				line = in.readLine();
				String[] ww = line.split(" ");
				String expr = ww[0];
				int k = Integer.valueOf(ww[1]);
				String[] items = expr.split("\\+");
				
				line = in.readLine();
				int n = Integer.valueOf(line);
				String[] words = new String[n];
				for (int i=0; i<n; i++) {
					words[i] = in.readLine();
				}
				
				long[] r = new long[k+1];
				
				Index temp = new Index();
				
				for (int it=0; it < items.length; it++) {
					String item = items[it];
					itemlen = item.length();
					
					// convert words to indexes
					Index[] windex = new Index[words.length];
					for (int w = 0; w <words.length; w++) {
						int[] current = new int[expr.length()];
						for (int wc = 0; wc < words[w].length(); wc++) {
							for (int ic = 0; ic < item.length(); ic++) {
								if (words[w].charAt(wc) == item.charAt(ic)) {
									current[ic] ++;
								}
							}
						}
						windex[w] = new Index(current);
					}
					
					HashMap<Index, VInt> hlast = null;
					HashMap<Index, VInt> hnew = new HashMap<Index, VInt>();
					hnew.put(new Index(), new VInt(1));
					for (int kk = 0; kk < k; kk++) {
						hlast = hnew;
						// System.err.println("item = " + item + " kk = " + kk + " hlast.size() = " + hlast.size());
						hnew = new HashMap<Index, VInt>();
						// update h[kk+1] from h[kk]
						int ee = 0;
						for (Map.Entry<Index, VInt> e: hlast.entrySet()) {
							Index currentkey = e.getKey();
							int currentvalue = e.getValue().v;
							// System.err.println("item = " + item + " kk = " + kk + " hlast.size() = " + hlast.size() + " " + (ee++) + " hnew.size()=" + hnew.size());
							for (int w = 0; w < words.length; w++) {
								temp.set(currentkey, windex[w]);
								if (kk < k - 1) {
									VInt v = hnew.get(temp);
									if (v == null) {
										hnew.put(new Index(temp), new VInt(currentvalue));
									} else {
										v.v += currentvalue;
									}
								}
								r[kk] = (r[kk] + currentvalue * temp.get()) % 10009;
							}
						}
					}
				}
				
				for (int kk = 0; kk < k; kk ++) {
					System.out.print(" " + r[kk]);
				}
				System.out.println();
			}
		} catch (Throwable e) {
			e.printStackTrace();
		}

	}

}
