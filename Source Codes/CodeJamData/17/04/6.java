// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class D_FashionShow { // small: OK, large: ?
  private static final String FILENAME="D-large";
  private static final boolean STANDARD_OUTPUT=false;
  public static void main(String[] args) throws Throwable {
    try (BufferedReader in=new BufferedReader(new FileReader(FILENAME+".in"))) {
      try (PrintStream out=!STANDARD_OUTPUT?new PrintStream(FILENAME+".out"):System.out) {
        for (int t=1,T=Integer.parseInt(in.readLine()); t<=T; t++) {
          StringTokenizer tokenizer=new StringTokenizer(in.readLine());
          int N=Integer.parseInt(tokenizer.nextToken());
          int M=Integer.parseInt(tokenizer.nextToken());
          char[][] map=create(N);
          for (int m=0; m<M; m++) {
            tokenizer=new StringTokenizer(in.readLine());
            char ch=tokenizer.nextToken().charAt(0);
            int r=Integer.parseInt(tokenizer.nextToken())-1;
            int c=Integer.parseInt(tokenizer.nextToken())-1;
            map[r][c]=ch;
          }
          char[][] originalMap=copy(map);
          int score=solve(N,map);
          List<String> updates=new ArrayList<>();
          for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
              if (map[r][c]!=originalMap[r][c]) updates.add(map[r][c]+" "+(r+1)+" "+(c+1));
            }
          }
          out.println("Case #"+t+": "+score+" "+updates.size());
          for (String update:updates) {
            out.println(update);
          }
        }
      }
    }
  }
  static int solve(int N, char[][] map) {
    Integer positions[]=new Integer[N*N];
    for (int r=0,k=0; r<N; r++) {
      for (int c=0; c<N; c++) {
        positions[k++]=(r<<16)|c;
      }
    }
    Arrays.sort(positions,new Comparator<Integer>() {
      @Override
      public int compare(Integer p1, Integer p2) {
        return rank(p1)-rank(p2);
      }
      int rank(int p) {
        int r=p>>>16,c=p&0xFFFF;
        return Math.min(Math.min(r,N-1-r),Math.min(c,N-1-c));
      }
    });
    int[] counter1=new int[N],counter2=new int[N],counter3=new int[2*N],counter4=new int[2*N];
    for (int p:positions) {
      int r=p>>>16,c=p&0xFFFF;
      char ch=map[r][c];
      if (ch!='.'&&ch!='+') {
        counter1[r]++;
        counter2[c]++;
      }
      if (ch!='.'&&ch!='x') {
        counter3[N+r-c]++;
        counter4[r+c]++;
      }
    }
    int score=0;
    for (int p:positions) {
      int r=p>>>16,c=p&0xFFFF;
      char ch=map[r][c];
      if (ch!='o') {
        for (int q=0,Q=ch=='.'?3:1; q<Q; q++) {
          char nch="ox+".charAt(q);
          boolean cond1=nch!='+'&&!(ch=='x'&&nch=='o');
          boolean cond2=nch!='x'&&!(ch=='+'&&nch=='o');
          if (cond1&&(counter1[r]>=1||counter2[c]>=1)) continue;
          if (cond2&&(counter3[N+r-c]>=1||counter4[r+c]>=1)) continue;
          if (cond1) counter1[r]++;
          if (cond1) counter2[c]++;
          if (cond2) counter3[N+r-c]++;
          if (cond2) counter4[r+c]++;
          ch=map[r][c]=nch;
          break;
        }
      }
      score+=ch=='o'?2:(ch!='.'?1:0);
    }
    return score;
  }
  static int[] counter1,counter2,counter3,counter4;
  static int bestScore;
  static int solveSlow(int N, char[][] map) {
    bestScore=0;
    counter1=new int[N];
    counter2=new int[N];
    counter3=new int[2*N];
    counter4=new int[2*N];
    for (int r=0; r<N; r++) {
      for (int c=0; c<N; c++) {
        if (map[r][c]!='.'&&map[r][c]!='+') {
          counter1[r]++;
          counter2[c]++;
        }
        if (map[r][c]!='.'&&map[r][c]!='x') {
          counter3[N+r-c]++;
          counter4[r+c]++;
        }
      }
    }
    solveSlow(N,map,0,0,0);
    return bestScore;
  }
  static void solveSlow(int N, char[][] map, int r, int c, int score) {
    if (r==N) {
      if (score>bestScore) bestScore=score;
    }
    else if (c==N) {
      solveSlow(N,map,r+1,0,score);
    }
    else if (map[r][c]=='o') {
      solveSlow(N,map,r,c+1,score+2);
    }
    else if (map[r][c]=='+') {
      solveSlow(N,map,r,c+1,score+1);
      if (counter1[r]>=1||counter2[c]>=1) return;
      map[r][c]='o';
      counter1[r]++;
      counter2[c]++;
      solveSlow(N,map,r,c+1,score+2);
      map[r][c]='+';
      counter1[r]--;
      counter2[c]--;
    }
    else if (map[r][c]=='x') {
      solveSlow(N,map,r,c+1,score+1);
      if (counter3[N+r-c]>=1||counter4[r+c]>=1) return;
      map[r][c]='o';
      counter3[N+r-c]++;
      counter4[r+c]++;
      solveSlow(N,map,r,c+1,score+2);
      map[r][c]='x';
      counter3[N+r-c]--;
      counter4[r+c]--;
    }
    else {
      for (char ch:new char[]{'o','+','x'}) {
        if (ch!='+'&&(counter1[r]>=1||counter2[c]>=1)) continue;
        if (ch!='x'&&(counter3[N+r-c]>=1||counter4[r+c]>=1)) continue;
        if (ch!='+') counter1[r]++;
        if (ch!='+') counter2[c]++;
        if (ch!='x') counter3[N+r-c]++;
        if (ch!='x') counter4[r+c]++;
        map[r][c]=ch;
        solveSlow(N,map,r,c+1,score+(ch=='o'?2:1));
        map[r][c]='.';
        if (ch!='+') counter1[r]--;
        if (ch!='+') counter2[c]--;
        if (ch!='x') counter3[N+r-c]--;
        if (ch!='x') counter4[r+c]--;
      }
      solveSlow(N,map,r,c+1,score);
    }
  }
  static void print(char[][] map) {
    for (char[] row:map) {
      System.out.println(new String(row));
    }
    System.out.println();
  }
  static char[][] copy(char[][] originalMap) {
    int N=originalMap.length;
    char[][] map=new char[N][N];
    for (int r=0; r<N; r++) {
      map[r]=originalMap[r].clone();
    }
    return map;
  }
  static char[][] create(int N) {
    char[][] map=new char[N][N];
    for (int r=0; r<N; r++) {
      Arrays.fill(map[r],'.');
    }
    return map;
  }
}
