import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int N = Integer.parseInt(br.readLine());

		for(int pp = 0; pp < N; pp++) {
			String[] ss = br.readLine().split(" ");

			int n = Integer.parseInt(ss[0]);
			int r = Integer.parseInt(ss[1]);
			int o = Integer.parseInt(ss[2]);
			int y = Integer.parseInt(ss[3]);
			int g = Integer.parseInt(ss[4]);
			int b = Integer.parseInt(ss[5]);
			int v = Integer.parseInt(ss[6]);

			boolean imp = false;
			String ret = "";

			if(r==0 && y==0 && g==0 && v==0) {
				if(o==b) {
					for(int i = 0; i < b; i++) ret = ret + "OB";
				} else {
					imp = true;
				}
			}

			if(r==0 && b==0 && g==0 && o==0) {
				if(v==y) {
					for(int i = 0; i < y; i++) ret = ret + "VY";
				} else {
					imp = true;
				}
			}

			if(b==0 && y==0 && o==0 && v==0) {
				if(g==r) {
					for(int i = 0; i < r; i++) ret = ret + "GR";
				} else {
					imp = true;
				}
			}

			if(!imp && ret.length() == 0) {


				if(o >= b && o > 0) {
					imp = true;
				} else {
					b -= o;
				}
				if(v >= y && v > 0) {
					imp = true;
				} else {
					y -= v;
				}
				if(g >= r && g > 0) {
					imp = true;
				} else {
					r -= g;
				}

				if(!imp) {

					int m = r+b+y;

					int[] c = new int[m];
					char max, mid, min;

					if(b >= r && b >= y) {
						max = 'B';
						if(r >= y) {
							mid = 'R';
							min = 'Y';
						} else {
							mid = 'Y';
							min = 'R';
						}
					} else if(r >= y) {
						max = 'R';
						if(b >= y) {
							mid = 'B';
							min = 'Y';
						} else {
							mid = 'Y';
							min = 'B';
						}
					} else {
						max = 'Y';
						if(b >= r) {
							mid = 'B';
							min = 'R';
						} else {
							mid = 'R';
							min = 'B';
						}
					}


					int[] vv = new int[3];
					vv[0] = b;
					vv[1] = r;
					vv[2] = y;
					Arrays.sort(vv);

					int tmp = vv[2];
					vv[2] = vv[0];
					vv[0] = tmp;

					c[0] = 0;
					int prev = 0;
					vv[0]--;
					for(int i = 1; i < m; i++) {
						int pick = -1;
						int aa = 0;
						int ab = 1;
						if(prev == 0) {
							aa = 1;
							ab = 2;
						}
						if(prev == 1) {
							aa = 0;
							ab = 2;
						}
						if(vv[aa] >= vv[ab]) {
							pick = aa;
						} else {
							pick = ab;
						}
						c[i] = pick;
						vv[pick]--;
						prev = pick;
						if(vv[pick] < 0) imp = true;
					}
					if(c[m-1]==c[0]) imp = true;
					//System.out.println(vv[0] + " " + vv[1] + " " + vv[2]);

					if(!imp) {
						boolean or = false;
						boolean gr = false;
						boolean vi = false;

						for(int i = 0; i < m; i++) {
							char add = (c[i] == 0 ? max : c[i] == 1 ? mid : min);
							ret = ret + add;
							if(add == 'R' && gr == false) {
								gr = true;
								for(int j = 0; j < g; j++) {
									ret = ret + "GR";
								}
							}
							if(add == 'B' && or == false) {
								or = true;
								for(int j = 0; j < o; j++) {
									ret = ret + "OB";
								}
							}
							if(add == 'Y' && vi == false) {
								vi = true;
								for(int j = 0; j < v; j++) {
									ret = ret + "VY";
								}
							}
						}
					}
				}

			}


			pw.println("Case #" + (pp+1) + ": " + (imp ? "IMPOSSIBLE" : ret));
		}


		pw.flush();
		pw.close();

	}
}