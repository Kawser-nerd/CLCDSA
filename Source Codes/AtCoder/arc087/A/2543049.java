import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i=0;i<n;i++){
			int x = sc.nextInt();
			if(map.containsKey(x)){
				int y = map.get(x);
				map.put(x, y+1);
			}
			else{
				map.put(x, 1);
				list.add(x);
			}
		}
		int count = 0;
		for(int i=0;i<list.size();i++){
			int x = list.get(i);
			int y = map.get(x);
			if(x<=y){
				count += y - x;
			}
			else{
				count += y;
			}
		}
		System.out.println(count);
	}
}