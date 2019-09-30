import java.util.*;

public class A {
	static final int MAX = 1000000;
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int C = sc.nextInt();
		for(int caseID = 1; caseID <= C; caseID++){
			int N = sc.nextInt();
			boolean oneBird = false;
			int bh1 = MAX + 1;
			int bh2 = -1;
			int bw1 = MAX + 1;
			int bw2 = -1;
			int[] Hs = new int[N];
			int[] Ws = new int[N];
			boolean[] bs = new boolean[N];
			for(int i = 0; i < N; i++){
				int H = sc.nextInt();
				int W = sc.nextInt();
				String X = sc.next();
				boolean b;
				if(X.equals("BIRD")){
					b = true;
					oneBird = true;
				}
				else{
					sc.next();
					b = false;
				}
				Hs[i] = H;
				Ws[i] = W;
				bs[i] = b;
				if(b){
					bh1 = Math.min(H, bh1);
					bh2 = Math.max(H, bh2);
					bw1 = Math.min(W, bw1);
					bw2 = Math.max(W, bw2);
				}
			}
			System.out.printf("Case #%d:%n", caseID);
			int M = sc.nextInt();
			for(int i = 0; i < M; i++){
				int H = sc.nextInt();
				int W = sc.nextInt();
				if(oneBird){
					boolean bird = false;
					// System.out.println(bh1 + " " + bh2 + " " + bw1 + " " + bw2);
					// System.out.println(H + " " + W);
					if(bh1 <= H && H <= bh2 && bw1 <= W && W <= bw2){
						bird = true;
					}
					boolean notBird = false;
					if(!bird){
						for(int j = 0; j < N; j++){
							if(!bs[j]){
								int NH = Hs[j];
								int NW = Ws[j];
								// System.out.println(bh1 + " " + bh2 + " " + bw1 + " " + bw2);
								// System.out.println(NH + " " + NW);
								if(NH < bh1 && NW < bw1){
									if(H <= NH && W <= NW) notBird = true;
								}
								else if(NH < bh1 && NW > bw2){
									if(H <= NH && W >= NW) notBird = true;
								}
								else if(NH > bh2 && NW > bw2){
									if(H >= NH && W >= NW) notBird = true;
								}
								else if(NH > bh2 && NW < bw1){
									if(H >= NH && W <= NW) notBird = true;
								}
								else if(NH < bh1){
									if(H <= NH) notBird = true;
								}
								else if(NH > bh2){
									if(H >= NH) notBird = true;
								}
								else if(NW < bw1){
									if(W <= NW) notBird = true;
								}
								else if(NW > bw2){
									if(W >= NW) notBird = true;
								}
								else throw new RuntimeException();
							}
						}
					}
					if(bird){
						System.out.println("BIRD");
					}
					else if(notBird){
						System.out.println("NOT BIRD");
					}
					else{
						System.out.println("UNKNOWN");
					}
				}
				else{
					boolean notBird = false;
					for(int j = 0; j < N; j++){
						if(!bs[j]){
							if(H == Hs[j] && W == Ws[j]){
								notBird = true;
							}
						}
						else throw new RuntimeException();
					}
					if(notBird){
						System.out.println("NOT BIRD");
					}
					else{
						System.out.println("UNKNOWN");
					}
				}
			}
		}
	}
}
