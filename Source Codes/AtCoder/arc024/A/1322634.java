import java.util.HashMap;
import java.util.Scanner;

public class Main {

	public static void main(String args[]){

		Scanner cin = new Scanner(System.in);
		int L = cin.nextInt();
		int R = cin.nextInt();
		int tmp;
		int result =0;
		HashMap<Integer,Integer> l = new HashMap<Integer,Integer>();
		HashMap<Integer,Integer> r = new HashMap<Integer,Integer>();

		for(int i=0;i<L;i++){
			tmp = cin.nextInt();
			if(l.containsKey(tmp)){
				l.put(tmp, l.get(tmp)+1);
			}else{
				l.put(tmp, 1);
			}
		}
		for(int j=0;j<R;j++){
			tmp = cin.nextInt();
			if(l.containsKey(tmp)){
				if(l.get(tmp)>0){
					result++;
					l.put(tmp, l.get(tmp)-1);
				}
			}
		}

		System.out.println(result);
	}
}