import java.util.Scanner;
import java.util.HashMap;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		HashMap<String,Integer> map=new HashMap<>();
		int ans=0;
		for(int i = 0; i<n; i++){
			String a=sc.next();
			if(map.containsKey(a)){
				map.put(a,map.get(a)+1);
			}else{
				map.put(a,1);
			}
		}
		int m = sc.nextInt();
		for(int i = 0; i<m; i++){
			String b=sc.next();
			if(map.containsKey(b)){
				map.put(b,map.get(b)-1);
			}else{
				map.put(b,-1);
			}
		}
		for(String i:map.keySet()){
			if(ans<map.get(i)){
				ans=map.get(i);
			}
		}
		System.out.println(ans);
	}
}