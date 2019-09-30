import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r=sc.nextInt();
        int c=sc.nextInt();
        int tmpR=sc.nextInt()-1;
        int tmpS=sc.nextInt()-1;
        String inputTmp;
        int gy=sc.nextInt()-1;
        int gx=sc.nextInt()-1;
        boolean[][] map=new boolean[r][c];
        int[][] bfs=new int[r][c];
        bfs[tmpR][tmpS]=1;
        for(int i=0;i<r;i++){
            inputTmp=sc.next();
            for(int j=0;j<c;j++){
                map[i][j]=inputTmp.charAt(j)=='.';
            }
        }
        Queue<Integer> nums=new ArrayDeque<>();
        nums.add(tmpR*c+tmpS);
        int size;
        while(true){
            size=nums.size();
            for(int i=0;i<size;i++){
                tmpR=nums.peek()/c;
                tmpS=nums.poll()%c;
                if(tmpR!=0&&map[tmpR-1][tmpS]&&bfs[tmpR-1][tmpS]==0){
                    bfs[tmpR-1][tmpS]=bfs[tmpR][tmpS]+1;
                    nums.add(c*(tmpR-1)+tmpS);
                }
                if(tmpS!=0&&map[tmpR][tmpS-1]&&bfs[tmpR][tmpS-1]==0){
                    bfs[tmpR][tmpS-1]=bfs[tmpR][tmpS]+1;
                    nums.add(c*(tmpR)+tmpS-1);
                }
                if(tmpR!=r-1&&map[tmpR+1][tmpS]&&bfs[tmpR+1][tmpS]==0){
                    bfs[tmpR+1][tmpS]=bfs[tmpR][tmpS]+1;
                    nums.add(c*(tmpR+1)+tmpS);
                }
                if(tmpS!=c-1&&map[tmpR][tmpS+1]&&bfs[tmpR][tmpS+1]==0){
                    bfs[tmpR][tmpS+1]=bfs[tmpR][tmpS]+1;
                    nums.add(c*(tmpR)+tmpS+1);
                }
                
            }
            if(bfs[gy][gx]!=0){
                System.out.println(bfs[gy][gx]-1);
                return;
            }
        }
        

    }
    

}