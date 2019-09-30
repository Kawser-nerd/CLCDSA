import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {
    	
    	int N = cin.nextInt();
    	int K = cin.nextInt();
    	int M = cin.nextInt();
    	
    	int pos[][] = new int[M][2];
    	int count[] = new int[K];
    	
    	for(int i = 0; i < M; ++i) {
    		// position;
    		pos[i][0] = cin.nextInt();
    		// buyer;
    		pos[i][1] = cin.nextInt();
    		++count[ pos[i][1] - 1 ];
    	}
    	
    	Arrays.sort(pos, new Comparator<int[]>() {
    		public int compare(int a[], int b[]) {
    			if( a[0] < b[0] ) { return -1; }
    			if( a[0] > b[0] ) { return 1; }
    			return a[1] - b[1];
    		}
    	});
    	
    	int min = 1;
    	for(int i = 0; i < K; ++i ) {
    		min = Math.max(min, count[i]);
    	}
    	
    	int result = 0;
    	int score = -1;
    	for( int i = min; i <= M; ++i ) {
    		score = solve(i, N, K, M, pos, count);
    		if( score >= 0 ) {
    			result = i;
    			break;
    		}
    	}

      System.out.println("Case #" + C + ": " + result + " " + score);

    }

    cin.close();

  }
  
  private int solve(int use, int N, int K, int M, int pos[][], int count[]) {
//	  System.err.println("check: " + use);
	  int Pable = 0;
	  int Pused = 0;
	  int p = 0;
	  for( int i = 1; i <= N; ++i ) {
		  int rest = use;
		  while( p < M ) {
//			  System.err.println(i + " " + p + " " + pos[p][0]);
			  if( pos[p][0] > i ) {
				  Pable += rest;
				  break;
			  }
			  if( pos[p][0] < i ) {
				  throw new RuntimeException("implementation ereror: invalid pos order: " + pos[p][0] + " < " + i);
			  }
			  if( rest == 0 ) {
				  // cannot fill;
				  if( Pable == 0 ) { return -1; }
				  --Pable;
				  ++Pused;
			  }
			  else {
				  --rest;
			  }
			  ++p;
		  }
	  }

	  return Pused;
  }

}
