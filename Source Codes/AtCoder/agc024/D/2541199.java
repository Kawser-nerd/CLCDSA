import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int N = cin.nextInt();
    int rank[] = new int[N];
    int mat[][] = new int[N][N];

    for( int i = 0; i < N - 1; ++i ) {
    	int L = cin.nextInt() - 1;
    	int R = cin.nextInt() - 1;
    	++rank[L];
    	++rank[R];
    	mat[L][R] = mat[R][L] = 1;
    }

    for( int k = 0; k < N; ++k ) {
    	for( int i = 0; i < N; ++ i ) {
    		for( int j = 0; j < N; ++j ) {
    			if( mat[i][k] > 0 && mat[k][j] > 0 ) {
    				if( mat[i][j] == 0 ) {
    					mat[i][j] = mat[i][k] + mat[k][j];
    				}
    				else {
    					mat[i][j] = Math.min(mat[i][j], mat[i][k] + mat[k][j]);
    				}
    			}
    		}
    	}
    }
    
    int S = -1;
    int T = -1;
    int maxD = 0;
    for( int i = 0; i < N; ++i ) {
    	if( rank[i] != 1 ) { continue; }
    	for( int j = i + 1; j < N; ++j ) {
    		if( rank[j] != 1 ) { continue; }
    		if( maxD < mat[i][j] ) {
    			maxD = mat[i][j];
    			S = i;
    			T = j;
    		}
    	}
    }
    
    if( N == 2 ) {
    	System.out.println("1 2");
    	cin.close();
    	return;
    }

    // even length == odd nodes (path);
    if( maxD % 2 == 0 ) {
    	int C = -1;
    	int D = maxD / 2;
    	for( int i = 0; i < N; ++i ) {
    		if( mat[S][i] == D && mat[T][i] == D ) {
    			if( C != -1 ) {
//    				throw new RuntimeException("double center...");
    			}
    			C = i;
    		}
    	}
    	int tmp[] = new int[N + 10];
    	Arrays.fill(tmp, 1);
    	score(C, -1, mat, N, 0, tmp);
    	long ans = 1;
    	for( int v : tmp ) {
    		ans *= v;
    	}
    	// add many edges to make tree like below;
    	for( int i = 0; i < N; ++i ) {
    		if( mat[C][i] == 1 ) {
    			int tmp2[] = new int[N + 10];
    			Arrays.fill(tmp2, 1);
    			score(C, i, mat, N, 0, tmp2);
    			score(i, C, mat, N, 0, tmp2);
    			long ans2 = 2;
    			for( int v : tmp2 ) {
    				ans2 *= v;
    			}
    			ans = Math.min(ans, ans2);
    		}
    	}
    	
    	System.out.println((maxD / 2 + 1) + " " + ans);
    	
    }

    // odd length == even nodes (path);
    else {
    	int C1 = -1;
    	int C2 = -1;
    	int D = maxD / 2;
    	for( int i = 0; i < N; ++i ) {
    		if( mat[S][i] == D && mat[T][i] == D + 1 ) {
    			if( C1 != -1 ) {
//    				throw new RuntimeException("double center...");
    			}
    			C1 = i;
    		}
    		if( mat[T][i] == D && mat[S][i] == D + 1 ) {
    			if( C2 != -1 ) {
//    				throw new RuntimeException("double center...");
    			}
    			C2 = i;
    		}
    	}
		int tmp[] = new int[N + 10];
		Arrays.fill(tmp, 1);
		score(C1, C2, mat, N, 0, tmp);
		score(C2, C1, mat, N, 0, tmp);
		long ans = 2;
		for( int v : tmp ) {
			ans *= v;
		}
		
    	System.out.println((maxD / 2 + 1) + " " + ans);

    }
    

    // ans 1;
    // maxD / 2 + 1;
    
    // ans 2 is ?;
    
    cin.close();

  }
  
  void score(int cur, int parent, int mat[][], int N, int level, int maxRank[]) {
	  int rank = 0;
	  for( int i = 0; i < N; ++i ) {
		  if( i == cur || i == parent ) { continue; }
		  if( mat[cur][i] == 1 ) {
			  ++rank;
			  score(i, cur, mat, N, level + 1, maxRank);
		  }
	  }
	  maxRank[level] = Math.max(maxRank[level], rank);
  }

}