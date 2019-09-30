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
				ret[i] = Integer.parseInt(tmp[i]);//Integer.parseInt(tmp[i]);
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	
	public static String find(int[] arr, int N, int count) {
		String ret = "";
		if (count < 3) {
			for (int i = 0; i < N; i++) {
				if (arr[i] > 0) {
					ret += Character.toString((char)('A' + i));
				}
			}
			
			return ret;
		}
		
		int r = (count + 1) / 2;
		for (int i = 0; i < N; i++) {
			if (arr[i] >= r) {
				ret += Character.toString((char)('A' + i));
				if (arr[i] > r) {
					ret += Character.toString((char)('A' + i));
				}
			}
		}
		
		if (ret.length() > 0)
			return ret;
		
		int ind = 0;
		for (int i = 1; i < N; i++) {
			if (arr[i] > arr[ind])ind = i;
		}
		
		ret += Character.toString((char)('A' + ind));
		
		return ret;
	}
	public static void main(String[] args) throws IOException {
		//Scanner in = new Scanner(System.in);
		br = new BufferedReader(new FileReader(new File("input.txt")));
		System.setOut(new PrintStream(new File("output.txt")));
		int T = readInt();
		
		for (int ind = 1; ind<=T; ind++) {
			System.out.print("Case #" + ind + ":");
			int sen[];
			int N = readInt();
			sen = readIntArr();
			int count = 0;
			for (int i = 0; i < N; i++)count+= sen[i];
			
			while(count > 0) {
				String k = find(sen, N, count);
				System.out.print(" " + k);
				count -= k.length();
				for (int j = 0; j < k.length(); j++) {
					sen[k.charAt(j) - 'A']--;
				}
			}
			System.out.println();
			
		}
		

	}

}
