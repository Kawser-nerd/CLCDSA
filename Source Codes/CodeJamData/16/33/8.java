package facebook;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class Qual {

	private static BufferedReader br = null;
	private static int readInt() {
		try {
			return Integer.parseInt(br.readLine());
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return 0;
	}
	
	private static double readDouble() {
		try {
			return Double.parseDouble(br.readLine());
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return 0;
	}
	
	private static int[] readIntArr() {
		int[] ret = null;
		String[] tmp;
		try {
			String str = br.readLine();
			tmp = str.split(" ");
			ret = new int[tmp.length];
			for (int i = 0; i < tmp.length; i++)
				ret[i] = Integer.parseInt(tmp[i]);
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	
	public static Map<Integer, Integer> map;
	
	public static int get(int i, int j, int k) {
		int c = 121 * i + 11 * j + k;
		
		if (!map.containsKey(c)) return 0;
		
		return map.get(c);
	}
	
	public static void add(int i, int j, int k) {
		int count = get(i, j, k);
		int c = 121 * i + 11 * j + k;
		
		map.put(c, count + 1);
		
	}
	
	public static void main(String[] args) throws IOException {
		//Scanner in = new Scanner(System.in);
		br = new BufferedReader(new FileReader(new File("input.txt")));
		System.setOut(new PrintStream(new File("output.txt")));
		int T = readInt();
		
		for (int ind = 1; ind<=T; ind++) {
			System.out.print("Case #" + ind + ": ");
			int sen[];
			sen = readIntArr();
			int I = sen[0];
			int J = sen[1];
			int K = sen[2];
			int M = sen[3];
			int count = 0;
			map = new HashMap<Integer, Integer>();
			
			for (int i = 1; i <= I; i++) {
				for (int jj = 1; jj <= J; jj++) {
					int j = (jj + i) % J + 1;
					int c = get(i, j, 0);
					if (c >= M) {
						continue;
					}
					
					for (int kk = 1; kk <= K; kk++) {
						int k = (kk + i + j) % K + 1;
						int ij = get(i, j, 0);
						if (ij >= M)continue;
						int ik = get(i, 0, k);
						if (ik >= M)continue;
						int jk = get(0, j, k);
						if (jk >= M)continue;
						
						count ++;
						add(i, j, k);
						add(i, j, 0);
						add(i, 0, k);
						add(0, j, k);
					}
				}
			}
			
			System.out.println(count);
			for (Entry<Integer, Integer> entry : map.entrySet()) {
				int key = entry.getKey();
				int k = key % 11;
				if (k == 0)continue;
				key /= 11;
				
				int j = key % 11;
				if (j == 0)continue;
				key /= 11;
				
				if (key == 0)continue;
				
				System.out.println(key + " " + j + " " + k);
			}
			
			
			
		}
		

	}

}
