import java.util.*;

public class Main {

  public static void main(String args[]) {
    int rep = 1;
    if( args.length > 0 ) { rep = Integer.parseInt(args[0]); }
    (new Main()).__solve(rep);
  }

  void __solve(int rep) {

    try (
      Scanner cin = new Scanner(System.in);
    ) {

      for( int i = 0; i < rep; ++i ) {
        __solve(cin);
      }

    }

  }

  void __solve(Scanner cin) {

	  String s = cin.next();
	  int K = cin.nextInt();
	  
	  int N = s.length();
	  String array[] = new String[N];
	  
	  for( int i = 0; i < N; ++i ) {
		  array[i] = s.substring(i);
	  }
	  
	  Arrays.sort(array);
	  
	  ans = null;
	  solve(0, 0, N, array, 0, K);
	  System.out.println(ans);

  }
  
  String ans = null;
  
  int solve(int depth, int start, int end, String array[], int total, int K) {
	  
	  if( ans != null ) {
		  return -1;
	  }
	  
	  // $ detected (skip);
	  if( array[start].length() == depth ) {
		  ++start;
	  }
	  
	  while( start < end ) {
		  char c = array[start].charAt(depth);
		  int next = start + 1;
		  for( ; next < end; ++next ) {
			  if( array[next].charAt(depth) != c ) {
				  break;
			  }
		  }
		  ++total;
		  if( total == K ) {
			  ans = array[start].substring(0, depth + 1);
			  return -1;
		  }
		  total = solve(depth + 1, start, next, array, total, K);
		  start = next;
	  }
	  
	  return total;

  }

}