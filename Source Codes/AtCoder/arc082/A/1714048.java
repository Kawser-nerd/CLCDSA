import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
	public static Map<Integer,Integer> map = new HashMap<Integer,Integer>();
	public static int max = 0;

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		try {

			int in1 = Integer.parseInt(br.readLine());
			String[] in2 = br.readLine().split(" ");

			for(String str :in2){
				int key = Integer.parseInt(str);
				setMap(key,0);
				setMap(key,+1);
				setMap(key,-1);
			}

			System.out.println(max);

		} catch (Exception e) {
			System.exit(0);
		}
    }

    public static void setMap(int key, int num){
		int key2 = key+num;
		int val = 0;
		if(map.containsKey(key2)){
			val = map.get(key2);
		}
		val += 1;
		map.put(key2, val);
		if(val > max){
			max = val;
		}
    }
}