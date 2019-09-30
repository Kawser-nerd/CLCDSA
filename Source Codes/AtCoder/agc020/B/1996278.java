import java.util.*;


public class Main {
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int n = sc.nextInt();
			int [] data = new int[n];
			for(int i = 0; i < n;i++){
				data[i] = sc.nextInt();
			}
			long min = 2;
			long max = 2;
			boolean flg = true;
			for(int i = n-1; i >= 0; i--){
				int now = data[i];
				long tempmin = now * (min / now + (min % now == 0 ? 0 : 1));
				long tempmax = now * (max / now + 1) - 1;
				if(! (min <= tempmin / now * now && tempmin / now * now <= max)){
					flg = false;
					break;
				}
				if(!(min <= tempmax / now * now && tempmax / now * now <= max)){
					flg = false;
					break;
				}
				min = tempmin;
				max = tempmax;
			}
			if(flg){
				System.out.println(min + " " + max);
			}
			else{
				System.out.println(-1);
			}
			
		}
	}



	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}

}