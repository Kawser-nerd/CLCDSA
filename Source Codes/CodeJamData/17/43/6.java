import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {
    	
    	int Row = cin.nextInt();
    	int Col = cin.nextInt();
    	String str[] = new String[Row];
    	for(int i = 0; i < Row; ++i ) {
    		str[i] = cin.next();
    	}

      System.out.println("Case #" + C + ": " + solve(str, Row, Col));

    }

    cin.close();

  }
  
  private String solve(String map[], int R, int C) {
	  int count = 0;
	  for(int i = 0; i < R; ++i ) {
		  for(int j = 0; j < C; ++j) {
			  char c = map[i].charAt(j);
			  if( c == '-' || c == '|' ) { ++count; }
		  }
	  }
	  int max = 1 << count;
	  for(int i = 0 ; i < max; ++i ) {
		  if( valid(i, map, R, C) ) {
			  return answer(i, map, R, C);
		  }
	  }
	  return "IMPOSSIBLE";
  }
  
  private static final int DL = 1;
  private static final int DR = 2;
  private static final int DU = 3;
  private static final int DD = 4;
  
  private int mirror(int prev, boolean slash) {
	  if( slash ) {
		  switch(prev) {
		  case DL:
			  return DD;
		  case DD:
			  return DL;
		  case DR:
			  return DU;
		  case DU:
			  return DR;
		  }
	  }
	  else {
		  switch(prev) {
		  case DL:
			  return DU;
		  case DU:
			  return DL;
		  case DR:
			  return DD;
		  case DD:
			  return DR;
		  }
	  }
	  throw new RuntimeException("unknown direction: " + prev);
  }
  
  private boolean check(String map[], int R, int C, int y, int x, int dir, boolean valid[][]) {
	  while( true ) {
		  // exited;
		  if( y < 0 || y >= R || x < 0 || x >= C ) { return true; }
		  char c = map[y].charAt(x);
		  // wall;
		  if( c == '#' ) { return true; }
		  // hit shooter;
		  else if( c == '-' || c == '|' ) {
			  // System.err.println("hit shooter @ " + y + ":" + x);
			  return false;
		  } 
		  else if( c == '.' ) {
			  valid[y][x] = true;
		  }
		  else if( c == '/' ) {
			  dir = mirror(dir, true);
		  }
		  else if( c == '\\' ) {
			  dir = mirror(dir, false);
		  }
		  else {
			  throw new RuntimeException("unknown chara: " + c);
		  }
		  switch(dir) {
		  case DL:
			  --x;
			  continue;
		  case DD:
			  ++y;
			  continue;
		  case DR:
			  ++x;
			  continue;
		  case DU:
			  --y;
			  continue;
		  }
	  }
  }
  
  private boolean valid(int state, String map[], int R, int C) {
	  boolean valid[][] = new boolean[R][C];
	  int read = 0;
	  for(int i = 0; i < R; ++i ) {
		  for( int j = 0; j < C; ++j ) {
			  char c = map[i].charAt(j);
			  if( c == '-' || c == '|' ) {
				  valid[i][j] = true;
				  // -;
				  if( (state & (1 << read)) == 0 ) {
					  // System.err.println("check h " + read + ":");
					  if( check(map, R, C, i, j - 1, DL, valid) == false ) { return false; }
					  if( check(map, R, C, i, j + 1, DR, valid) == false ) { return false; }
					  // System.err.println("success");
				  }
				  // |;
				  else {
					  // System.err.println("check v " + read + ":");
					  if( check(map, R, C, i - 1, j, DU, valid) == false ) { return false; }
					  if( check(map, R, C, i + 1, j, DD, valid) == false ) { return false; }
					  // System.err.println("success");
				  }
				  ++read;
			  }
			  else if( c != '.' ) {
				  valid[i][j] = true;
			  }
		  }
	  }
	  for(int i = 0; i < R; ++i ) {
		  for(int j = 0; j < C; ++j ) {
			  if( valid[i][j] == false ) {
				  // System.err.println("not filled @ " + i + ":" + j);
				  return false;
			  }
		  }
	  }
	  return true;
  }
  
  private String answer(int state, String map[], int R, int C) {
	  int read = 0;
	  String result = "POSSIBLE";
	  for(int i = 0; i < R; ++i ) {
		  result += "\n";
		  for(int j = 0; j < C; ++j) {
			  char c = map[i].charAt(j);
			  if( c == '-' || c == '|' ) {
				  if( (state & (1 << read)) == 0 ) {
					  result += '-';
				  }
				  else {
					  result += '|';
				  }
				  ++read;
			  }
			  else {
				  result += c;
			  }
		  }
	  }
	  return result;
  }

}
