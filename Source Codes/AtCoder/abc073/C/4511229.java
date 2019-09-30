import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
		int n=Integer.parseInt(br.readLine());
		Map<Integer, Integer> map=new HashMap<Integer,Integer>();
		int count=0;
		for(int i=0;i<n;i++){
			int a=Integer.parseInt(br.readLine());
			if(!map.containsKey(a)){
				map.put(a, 1);
				count++;
			}else{
				map.remove(a);
				count--;
			}
		}
		System.out.println(count);
	}
}