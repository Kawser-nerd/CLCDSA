package r3;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class B {
  static final int WALL = 0;
  static final int EMPTY = 1;
  static int shoot(int map[][] , int cx , int cy , int dx , int dy){
    while(true){
      if(map[cy][cx] == WALL){
        return cy * (map[cy].length) + cx;
      }
      cx += dx;
      cy += dy;
    }
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    for(int cn = 1 ; cn <= N ; cn++){
      int R = sc.nextInt();
      int C = sc.nextInt();
      int map[][] = new int[R + 2][C + 2];
      int pos =  -1;
      int cake = -1;
      int area = (R + 2) * (C + 2);
      for(int i = 0 ; i < R ; i++){
        String row = sc.next();
        for(int j = 0 ; j < C ; j++){
          char ch = row.charAt(j);
          int x = j + 1;
          int y = i + 1;
          int p = y * (C + 2) + x;
          if(ch == '.'){
            map[y][x] = EMPTY;
          }else if(ch == 'O'){
            map[y][x] = EMPTY;
            pos = p;
          }else if(ch == 'X'){
            map[y][x] = EMPTY;
            cake = p;
          }else if(ch == '#'){
            map[y][x] = WALL;
          }
        }
      }
      boolean memo[][][] = new boolean[area][area * 4][area * 4];
      int north = 0;
      int east = 1;
      int south = 2;
      int west = 3;
      int ans = -1;
      int ns = shoot(map, pos % (C + 2), pos / (C + 2), 0, -1);
      int ss = shoot(map, pos % (C + 2), pos / (C + 2), 0,  1);
      State s = new State(pos , ns * 4 + south, ss * 4 + north , 0);
      memo[pos][ns * 4 + south][ss * 4 + north] = true;
      Queue<State> q = new PriorityQueue<State>();
      q.add(s);
      while(!q.isEmpty()){
        State cp = q.poll();
        int turn = cp.turn;
        if(cp.pos == cake){
          ans = turn;
          break;
        }
        int cx = cp.pos % (C + 2);
        int cy = cp.pos / (C + 2);
        //move
        for(int dx = -1 ; dx <= 1 ; dx++){
          for(int dy = -1 ; dy <= 1 ; dy++){            
            if(dx == 0 && dy == 0)continue;
            if(dx * dy != 0)continue;
            int nx = cx + dx;
            int ny = cy + dy;
            if(map[ny][nx] == WALL){
              //check portal
              int p = (ny * (C + 2)) + nx;
              if(cp.blue / 4 == p){
                int dir = cp.yellow % 4;
                nx = (cp.yellow / 4) % (C + 2);
                ny = (cp.yellow / 4) / (C + 2);
                if(dir == north){
                  ny--;
                }else if(dir == south){
                  ny++;
                }else if(dir == east){
                  nx++;
                }else{
                  nx--;
                }
              }else if(cp.yellow / 4== p){
                int dir = cp.blue % 4;
                nx = (cp.blue / 4) % (C + 2);
                ny = (cp.blue / 4) / (C + 2);
                if(dir == north){
                  ny--;
                }else if(dir == south){
                  ny++;
                }else if(dir == east){
                  nx++;
                }else{
                  nx--;
                }
              }else{
                continue;                
              }
            }
            int np = ny * (C + 2) + nx;
            if(!memo[np][cp.blue][cp.yellow]){
              memo[np][cp.blue][cp.yellow] = true;
              q.add(new State(np , cp.blue , cp.yellow , turn + 1));
            }
          }
        }
        //shoot portal
        for(int dx = -1 ; dx <= 1 ; dx++){
          for(int dy = -1 ; dy <= 1 ; dy++){            
            if(dx == 0 && dy == 0)continue;
            if(dx * dy != 0)continue;
            int sh = shoot(map, cx, cy, dx, dy);
            int dir = -1;
            if(dx != 0){
              dir = dx < 0 ? east : west;
            }else{
              dir = dy < 0 ? south : north;
            }
            int b = sh * 4 + dir;
            if(!memo[cp.pos][b][cp.yellow]){
              memo[cp.pos][b][cp.yellow] = true;
              q.add(new State(cp.pos , b , cp.yellow , turn));
            }
            int y = sh * 4 + dir;
            if(!memo[cp.pos][cp.blue][y]){
              memo[cp.pos][cp.blue][y] = true;
              q.add(new State(cp.pos ,cp.blue ,y , turn));
            }            
          }
        }
      }
      System.out.printf("Case #%d: " , cn);
      if(ans < 0){
        System.out.println("THE CAKE IS A LIE");
      }else{
        System.out.println(ans);
      }
    }
  }
  
}
class State implements Comparable<State>{
  int blue;
  int yellow;
  int pos;
  int turn;
  State(int p , int b , int y , int t){
    pos = p; 
    blue = b; 
    yellow = y;
    turn = t;
  }
  public int compareTo(State o) {
    return turn - o.turn;
  }
}
