import java.util.*;

public class B {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int N = sc.nextInt();
		for(int id = 1; id <= N; id++){
			int T = sc.nextInt();
			int NA = sc.nextInt();
			int NB = sc.nextInt();
			int[] waitA = new int[3000];
			int[] waitB = new int[3000];
			ArrayList<Integer>[] As = (ArrayList<Integer>[])new ArrayList[3000];
			ArrayList<Integer>[] Bs = (ArrayList<Integer>[])new ArrayList[3000];
			for(int t = 0; t < 3000; t++){
				As[t] = new ArrayList<Integer>();
				Bs[t] = new ArrayList<Integer>();
			}
			for(int i = 0; i < NA; i++){
				int t1 = timeToInt(sc.next());
				int t2 = timeToInt(sc.next());
				As[t1].add(t2 + T);
			}
			for(int i = 0; i < NB; i++){
				int t1 = timeToInt(sc.next());
				int t2 = timeToInt(sc.next());
				Bs[t1].add(t2 + T);				
			}
			int dA = 0;
			int dB = 0;
			for(int t = 0; t < 2400; t++){
				for(int t2 : As[t]){
					if(waitA[t] > 0){
						waitA[t]--;
					}
					else{
						dA++;
					}
					waitB[t2]++;
				}
				for(int t2 : Bs[t]){
					if(waitB[t] > 0){
						waitB[t]--;
					}
					else{
						dB++;
					}
					waitA[t2]++;
				}
				if(waitA[t] > 0) waitA[t + 1] += waitA[t];
				if(waitB[t] > 0) waitB[t + 1] += waitB[t];
			}
			System.out.printf("Case #%d: %d %d %n", id, dA, dB);
		}
	}
	private static int timeToInt(String str){
		String[] words = str.split(":");
		return Integer.parseInt(words[0]) * 60 + Integer.parseInt(words[1]);
	}
}
