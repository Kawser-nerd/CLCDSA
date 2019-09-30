import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;


public class Main {

	public class Sol {
		int [][] ar;
		public Sol(int r , int c) {
			ar = new int[r][c];
		}
		public Sol(int[][]a) {
			ar = a;
		}
	}
	
	static Main main;
	
	static int r,c;
	
	public static void main(String[] args) {
		main = new Main();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedOutputStream bos = new BufferedOutputStream(System.out);
		String eol = System.getProperty("line.separator");
		byte[] eolb = eol.getBytes();
		try {
			String str = br.readLine();
			int t = Integer.parseInt(str);
			long sp = 1000000007;
			for(int i = 0 ; i < t ; i++) {
				long ans = 0;
				str = br.readLine();
				int blank = str.indexOf(" ");
				r = Integer.parseInt(str.substring(0, blank));
				c = Integer.parseInt(str.substring(blank+1));
				ArrayList<Sol> csol = new ArrayList<Sol>();
				int [][] cc = new int[r][c];
				for(int j = 0 ; j < r ; j++) {
					Arrays.fill(cc[j], 100);
				}
				csol.add(main.new Sol(cc));
				for(int j = 0 ; j < r ; j++) {
					for(int k = 0 ; k < c ; k++) {
						ArrayList<Sol> rsol = new ArrayList<Sol>();
						for(int num = 1 ; num < 4 ; num++) {
							for(int a = 0 ; a < csol.size() ; a++) {
								Sol solb = csol.get(a);
								int [][] arar = new int[r][c];
								for(int xx = 0 ; xx < r ; xx++) {
									for(int yy = 0 ; yy < c ; yy++) {
										arar[xx][yy] = solb.ar[xx][yy];
									}
								}
								arar[j][k] = num;
								if(checkValid(arar,j,k)) {
									rsol.add(main.new Sol(arar));
								}
							}
						}
						csol = rsol;
					}
				}
				ans = 0;
				ArrayList<Sol> fin = new ArrayList<Sol>();
				for(int a = 0 ; a < csol.size() ; a++) {
					if(fullValid(csol.get(a).ar)) {
						fin.add(csol.get(a));
						/*
						for(int b = 0 ; b < r ; b++) {
							for(int bb = 0 ; bb < c ; bb++) {
								System.out.print(csol.get(a).ar[b][bb] + " ");
							}
							System.out.println();
						}
						*/
					}
				}
				csol = fin;
				fin = new ArrayList<Sol>();
				for(int a = 0 ; a < csol.size() ; a++) {
					Sol or = csol.get(a);
					boolean repeat = false;
					for(int b = a+1 ; b < csol.size(); b++) {
						Sol ror = csol.get(b);
						for(int rot = 1 ; rot < c ; rot++) {
							int [][] ar2 = ror.ar;
							int [][] car2 = new int[r][c];
							for(int ca = 0 ; ca < r ; ca++) {
								for(int cb = 0 ; cb < c ; cb++) {
									car2[ca][(cb+rot)%c] = ar2[ca][cb];
								}
							}
							boolean same = true;
							for(int ca = 0 ; ca < r ; ca++) {
								for(int cb = 0 ; cb < c ; cb++) {
									if(or.ar[ca][cb] != car2[ca][cb]) {
										same = false;
										break;
									}
								}
							}
							if(same) {
								repeat = true;
							}
						}
					}
					if(!repeat) {
						fin.add(csol.get(a));
					}
				}
				ans = fin.size();
				ans = ans % sp;
				bos.write("Case #".getBytes());
				bos.write(new Integer(i+1).toString().getBytes());
				bos.write(": ".getBytes());
				bos.write(new Long(ans).toString().getBytes());
				bos.write(eolb);
			}
			bos.flush();
		} catch(IOException ioe) {
			ioe.printStackTrace();
		}

	}

	public static boolean checkValid(int[][]ar,int a , int b) {
		for(int i = 0 ; i <= a ; i++) {
			int max = c-1;
			if(i==a) {
				max = b;
			}
			for(int j = 0 ; j <=max ; j++) {
				int c1 = count(ar,i,j,ar[i][j]);
				int c2 = count(ar,i,j,100) + c1 ;
				if((ar[i][j]<c1)||(ar[i][j]>c2)) {
					return false;
				}
			}
		}
		return true;
	}
	
	public static boolean fullValid(int[][]ar) {
		for(int i = 0 ; i < r ; i++) {
			for(int j = 0 ; j < c ; j++) {
				if(ar[i][j]!=count(ar,i,j,ar[i][j])) {
					return false;
				}
			}
		}
		return true;
	}
	
	public static int count(int [][]ar,int i , int j , int tc) {
		int ans = 0;
		if(i!=0) {
			if(ar[i-1][j]==tc) {
				ans++;
			}
		} 
		if(j!=0) {
			if(ar[i][j-1]==tc) {
				ans++;
			}
		} else {
			if(ar[i][c-1]==tc) {
				ans++;
			}
		}
		if(i!=(r-1)) {
			if(ar[i+1][j]==tc) {
				ans++;
			}
		} 
		if(j!=(c-1)) {
			if(ar[i][j+1]==tc) {
				ans++;
			}
		} else {
			if(ar[i][0]==tc) {
				ans++;
			}
		}
		return ans;
	}
}
