import java.io.*;
import java.util.*;

public class Gcjr1p3 {
	public static final int PLUS = 10, MINUS = 11, DEFAULTPLUS = 1000;
	
	public static final int[] dirsa = new int[] {-1, 0, 0, 1};
	public static final int[] dirsb = new int[] {0, -1, 1, 0};
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
			PrintWriter pw = new PrintWriter(new FileWriter("result.txt"));
			
			String s = br.readLine();
			
			int T = Integer.parseInt(s);
			for(int i = 1; i <= T; i++) {
				s = br.readLine();
				String[] ss = s.split(" ");
				int W = Integer.parseInt(ss[0]);
				int Q = Integer.parseInt(ss[1]);
				
				int[][] map = new int[W][W];
				for(int j = 0; j < W; j++) {
					s = br.readLine();
					char[] chrs = s.toCharArray();
					for(int k = 0; k < W; k++) {
						if(chrs[k] == '+') {
							map[j][k] = PLUS;
						} else if(chrs[k] == '-') {
							map[j][k] = MINUS;
						} else {
							map[j][k] = chrs[k] - '0';
						}
					}
				}
				
				s = br.readLine();
				ss = s.split(" ");
				int[] nrs = new int[ss.length];
				TreeSet<Integer> set = new TreeSet<Integer>();
				for (int j = 0; j < nrs.length; j++) {
					nrs[j] = Integer.parseInt(ss[j]);
					set.add(nrs[j]);
				}
				
				TreeMap<Integer, String> tmap = new TreeMap<Integer, String>();
				int nrProcessed = 0;
				
				LinkedList<Integer> lla = new LinkedList<Integer>();
				LinkedList<Integer> llb = new LinkedList<Integer>();
				LinkedList<Integer> llv = new LinkedList<Integer>();
				
				int[][][] dp = new int[W][W][2*DEFAULTPLUS];
				String[][][] dps = new String[W][W][2*DEFAULTPLUS];
				for(int a = 0; a < W; a++) {
					for(int b = 0; b < W; b++) {
						if(map[a][b] != PLUS && map[a][b] != MINUS) {
							dp[a][b][map[a][b] + DEFAULTPLUS] = 1;
							dps[a][b][map[a][b] + DEFAULTPLUS] = "" + map[a][b];
							if(set.contains(map[a][b]) && !tmap.containsKey(map[a][b])) {
								tmap.put(map[a][b], "" + map[a][b]);
								nrProcessed++;
							}
							
							lla.add(a);
							llb.add(b);
							llv.add(map[a][b] + DEFAULTPLUS);
						}
					}
				}
				
				
				while(nrProcessed < set.size()) {
					LinkedList<Integer> lla2 = new LinkedList<Integer>();
					LinkedList<Integer> llb2 = new LinkedList<Integer>();
					LinkedList<Integer> llv2 = new LinkedList<Integer>();
					
					while(lla.size() > 0) {
						int a = lla.removeFirst();
						int b = llb.removeFirst();
						int v = llv.removeFirst();
						
						int nr = dp[a][b][v];
						
						for(int x = 0; x < dirsa.length; x++) {
							if(a + dirsa[x] >= 0 && a + dirsa[x] < W && b + dirsb[x] >= 0 && b + dirsb[x] < W) {
								int ax = a + dirsa[x], bx = b + dirsb[x];
								char sign = map[a + dirsa[x]][b + dirsb[x]] == PLUS ? '+' : '-';
								for(int y = 0; y < dirsa.length; y++) {
									if(ax + dirsa[y] >= 0 && ax + dirsa[y] < W && bx + dirsb[y] >= 0 && bx + dirsb[y] < W) {
										int ay = ax + dirsa[y], by = bx + dirsb[y];

										int mapVal = map[ay][by];
										int nv = v - mapVal;
										if(map[ax][bx] == PLUS) {
											nv = v + mapVal;
										}
								
										if(dp[ay][by][nv] == 0 || dp[ay][by][nv] == nr + 1) {
											dp[ay][by][nv] = nr + 1;
											if(dps[ay][by][nv] == null) {
												dps[ay][by][nv] = dps[a][b][v] + sign + map[ay][by];
												lla2.add(ay);
												llb2.add(by);
												llv2.add(nv);
											} else {
												String nval = dps[a][b][v] + sign + map[ay][by];
												if(nval.compareTo(dps[ay][by][nv]) < 0) {
													dps[ay][by][nv] = nval;
													lla2.add(ay);
													llb2.add(by);
													llv2.add(nv);
												}
											}
											if(set.contains(nv - DEFAULTPLUS)) {
												if(!tmap.containsKey(nv - DEFAULTPLUS)) {
													tmap.put(nv - DEFAULTPLUS, dps[ay][by][nv]);
													nrProcessed++;
												} else {
													String val = tmap.get(nv - DEFAULTPLUS);
													if(val.length() == dps[ay][by][nv].length() && dps[ay][by][nv].compareTo(val) < 0) {
														tmap.put(nv - DEFAULTPLUS, dps[ay][by][nv]);
													}
												}
											}
										}
									}
								}
							}
						}
					}
					
					lla = lla2;
					llb = llb2;
					llv = llv2;
				}
				
				pw.println("Case #" + i + ":");
				for (int j = 0; j < nrs.length; j++) {
					pw.println(tmap.get(nrs[j]));
				}
			}
			
			pw.close();
		}catch (Exception e) {
			e.printStackTrace();
		}
	}
}
