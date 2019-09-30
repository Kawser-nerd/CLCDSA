import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Integer wordNum = Integer.valueOf(br.readLine());
		String[] param = br.readLine().split(" ");

		List<String> resList = new ArrayList<>();
		for(int i = 0; i < wordNum; i++) {
			String tmp = "";
			String str = param[i];
			str = str.toLowerCase();
			for(int j = 0; j < str.length(); j++) {
				if(str.charAt(j) == 'b' || str.charAt(j) == 'c') {
					tmp = tmp + "1";
				} else if(str.charAt(j) == 'd' || str.charAt(j) == 'w') {
					tmp = tmp + "2";
				} else if(str.charAt(j) == 't' || str.charAt(j) == 'j') {
					tmp = tmp + "3";
				} else if(str.charAt(j) == 'f' || str.charAt(j) == 'q') {
					tmp = tmp + "4";
				} else if(str.charAt(j) == 'l' || str.charAt(j) == 'v') {
					tmp = tmp + "5";
				} else if(str.charAt(j) == 's' || str.charAt(j) == 'x') {
					tmp = tmp + "6";
				} else if(str.charAt(j) == 'p' || str.charAt(j) == 'm') {
					tmp = tmp + "7";
				} else if(str.charAt(j) == 'h' || str.charAt(j) == 'k') {
					tmp = tmp + "8";
				} else if(str.charAt(j) == 'n' || str.charAt(j) == 'g') {
					tmp = tmp + "9";
				} else if(str.charAt(j) == 'z' || str.charAt(j) == 'r') {
					tmp = tmp + "0";
				}
			}
			resList.add(tmp);
		}

		String result = "";
		for(String s : resList) {
			if(!s.equals("")) {
				result = result + s + " ";
			}
		}
		if(result.equals("")) {
			System.out.println();
			return;
		}

		System.out.println(result.substring(0, result.length()-1));
	}
}