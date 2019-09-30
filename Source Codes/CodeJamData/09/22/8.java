import java.io.*;
import java.util.*;

public class Gcjr1p2 {
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
			PrintWriter pw = new PrintWriter(new FileWriter("result.txt"));
			
			String s = br.readLine();
			
			int T = Integer.parseInt(s);
			for(int i = 1; i <= T; i++) {
				String res = br.readLine();
				char[] chrs = res.toCharArray();
				ArrayList<Integer> list = new ArrayList<Integer>();
				boolean ok = false;
				for(int j = res.length() - 1; j > 0; j--) {
					char chr1 = res.charAt(j), chr2 = res.charAt(j - 1);
					list.add(chr1 - '0');
					if(chr1 > chr2) {
						int[] lst = new int[list.size()];
						int k = 0;
						for(int val : list) {
							lst[k] = val;
							k++;
						}
						
						Arrays.sort(lst);
						
						int choosen = -1;
						for(k = 0; k < lst.length; k++) {
							if(lst[k] > chr2 - '0') {
								choosen = k;
								break;
							}
						}
						
						chrs[j - 1] = (char)(lst[choosen] + '0');
						lst[choosen] = chr2 - '0';
						Arrays.sort(lst);
						for(k = 0; k < lst.length; k++) {
							chrs[k + j] = (char)(lst[k] + '0');
						}
						ok = true;
						break;
					}
				}
				
				if(ok) {
					pw.println("Case #" + i + ": " + new String(chrs));
				} else {
					list.add(res.charAt(0) - '0');
					int[] lst = new int[list.size()];
					int k = 0;
					for(int val : list) {
						lst[k] = val;
						k++;
					}
					Arrays.sort(lst);
					
					int choosen = -1;
					for(k = 0; k < lst.length; k++) {
						if(lst[k] > 0) {
							choosen = k;
							break;
						}
					}
					
					chrs = new char[chrs.length + 1];
					chrs[0] = (char)(lst[choosen] + '0');
					chrs[1] = '0';
					for(int u = 0; u < lst.length; u++) {
						if(u == choosen) {
							continue;
						}
						if(u < choosen) {
							chrs[u + 2] = (char)(lst[u] + '0');
						} else {
							chrs[u + 1] = (char)(lst[u] + '0');
						}
					}
					pw.println("Case #" + i + ": " + new String(chrs));
				}
			}
			
			pw.close();
		}catch (Exception e) {
			e.printStackTrace();
		}
	}
}
