import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int k = sc.nextInt();
		ArrayList<String> list = new ArrayList<String>();
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		for(int i=0;i<s.length();i++){
			for(int j=1;j<=5;j++){
				if(i+j>s.length()){
					break;
				}
				String t = s.substring(i, i+j);
				if(!map.containsKey(t)){
					map.put(t, 1);
					list.add(t);
				}
			}
		}
		Collections.sort(list);
		System.out.println(list.get(k-1));
	}
}