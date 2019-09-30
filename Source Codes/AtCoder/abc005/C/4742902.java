import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int T = sc.nextInt();
	int N = sc.nextInt();
	int[] tako = new int[200+1];
	for(int i = 0; i<N; i++) {
	    int start = sc.nextInt();
	    tako[start]++;
	}
	int M = sc.nextInt();
	for(int j = 0; j<M; j++) {
	    int comeT = sc.nextInt();
	    for(int i = Math.max(0, comeT-T); i<=comeT; i++) {
		if(tako[i]>0) {
		    tako[i]--;
		    break;
		}
		if(i==comeT) {
		    System.out.println("no");
		    return;
		}
	    }
	}

	System.out.println("yes");
    }
}