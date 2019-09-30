import java.math.BigInteger;
import java.util.*;


public class Main {
	
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int n = sc.nextInt();
			int [] data = new int[n];
			for(int i = 0; i < n; i++){
				data[i] = sc.nextInt();
			}
			
			long count = 0;
			int now = 0;
			int left = 0, right = 0;
			while(true){
				if(left >= n){
					break;
				}
				while(right < n){
					int res = now ^ data[right];
					int res2 = now | data[right];
					if(res != res2){
						break;
					}
					now = now ^ data[right];
					right++;
				}
				count += right - left;
				now = now ^ (now & data[left]);
				left++;
			}
			System.out.println(count);
		}
	}

	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}

}