import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class Stable {
	public static void main(String[] args) throws IOException{
		BufferedReader buf = new BufferedReader(new FileReader("stable.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("stable.out")));
		int t = Integer.parseInt(buf.readLine());
		for(int i = 0; i < t; i++) {
			//System.out.println(i);
			String[] s = buf.readLine().split(" ");
			int n = Integer.parseInt(s[0]);
			int r = Integer.parseInt(s[1]);
			int o = Integer.parseInt(s[2]);
			int y = Integer.parseInt(s[3]);
			int g = Integer.parseInt(s[4]);
			int b = Integer.parseInt(s[5]);
			int v = Integer.parseInt(s[6]);
			if(r == g && o == 0 && y == 0 && b == 0 && v == 0){
				String str = "";
				for(int k = 0; k < r; k++){
					str = str + "RG";
				}
				out.println("Case #" + (i + 1) + ": " + str);
				continue;
			} else if(b == o && r == 0 && y == 0 && g == 0 && v == 0){
				String str = "";
				for(int k = 0; k < b; k++){
					str = str + "BO";
				}
				out.println("Case #" + (i + 1) + ": " + str);
				continue;
			} else if(y == v && o == 0 && r == 0 && b == 0 && g == 0){
				String str = "";
				for(int k = 0; k < v; k++){
					str = str + "YV";
				}
				out.println("Case #" + (i + 1) + ": " + str);
				continue;
			} 
			r = r - g;
			y = y - v;
			b = b - o;
			n = n - g - v - o - g - v - o;
			System.out.println(i + " " + r + " " + y + " " + b);
			if(r < 0 || y < 0 || b < 0 || (r == 0 && g > 0) || (y == 0 && v > 0) || (b == 0 && o > 0)){
				out.println("Case #" + (i + 1) + ": IMPOSSIBLE");
				continue;
			}
			String str = init(r, y, b, n);
			if(str == null){
				out.println("Case #" + (i + 1) + ": IMPOSSIBLE");
				continue;
			}
			//System.out.println(i);
			for(int j = 0; j < str.length(); j++){
				if(str.charAt(j) == 'R'){
					r--;
				} else if (str.charAt(j) == 'Y'){
					y--;
				} else {
					b--;
				}
			}
			str = make(r, y, b, str);
			//System.out.println(i);
			for(int j = 0; j < str.length(); j++){
				if(str.charAt(j) == 'R'){
					for(int k = 0; k < g; k++){
						str = str.substring(0, j) + "RG" + str.substring(j);
					}
					break;
				} 
			}
			for(int j = 0; j < str.length(); j++){
				if(str.charAt(j) == 'Y'){
					for(int k = 0; k < v; k++){
						str = str.substring(0, j) + "YV" + str.substring(j);
					}
					break;
				} 
			}
			for(int j = 0; j < str.length(); j++){
				if(str.charAt(j) == 'B'){
					for(int k = 0; k < o; k++){
						str = str.substring(0, j) + "BO" + str.substring(j);
					}
					break;
				} 
			}
			out.println("Case #" + (i + 1) + ": " + str);
		}
		out.close();
	}
	public static String init(int r, int g, int b, int n){
		if(r == n || g == n || b == n){
			return null;
		}
		if(r > n/2 || g > n/2 || b > n/2){
			return null;
		}
		if(r == 0){
			if(g == b){
				return "BY";
			} else return null;
		} else if (g == 0){
			if(r == b){
				return "BR";
			} else return null;
		} else if (b == 0){
			if(r == g){
				return "YR";
			} else return null;
		}
		if(n % 2 == 0){
			if(r > g && r > b){
				return "RYRB";
			} else if (g > b){
				return "YRYB";
			} else {
				return "BRBY";
			}
		} else {
			return "RYB";
		}
	}
	public static String make(int r, int g, int b, String s){
		while(r + g + b > 0) {
			//System.out.println(r + g + b);
			if(r < g && r < b){
				g--;
				b--;
				for(int i = 0; i < s.length(); i++){
					//System.out.println(r + g + b + "a");
					if(s.charAt(i) != 'R'){
						if(s.charAt(i) == 'Y'){
							s = s.substring(0, i) + "YB" + s.substring(i);
						} else {
							s = s.substring(0, i) + "BY" + s.substring(i);
						}
						break;
					}
				}
			} else if (g < b){
				r--;
				b--;
				for(int i = 0; i < s.length(); i++){
					//System.out.println(r + g + b + "b");
					if(s.charAt(i) != 'Y'){
						if(s.charAt(i) == 'R'){
							s = s.substring(0, i) + "RB" + s.substring(i);
						} else {
							s = s.substring(0, i) + "BR" + s.substring(i);
						}
						break;
					}
				}
			} else {
				r--;
				g--;
				for(int i = 0; i < s.length(); i++){
					//System.out.println(r + g + b + "c");
					if(s.charAt(i) != 'B'){
						if(s.charAt(i) == 'R'){
							s = s.substring(0, i) + "RY" + s.substring(i);
						} else {
							s = s.substring(0, i) + "YR" + s.substring(i);
						}
						break;
					}
				}
			}
		}
		return s;
	}
}
