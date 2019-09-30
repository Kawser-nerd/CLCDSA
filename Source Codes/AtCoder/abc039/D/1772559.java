import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int h=scan.nextInt();
        int w=scan.nextInt();
        String[] s=new String[h];
        for(int i=0;i<h;++i)
            s[i]=scan.next();
        int[][] a=new int[h][w];
        for(int i=0;i<h;++i)Arrays.fill(a[i],1);
        for(int i=0;i<h;++i)
            for(int j=0;j<w;++j){
                if(s[i].charAt(j)=='.')
                    for(int dx=-1;dx<=1;++dx)
                        for(int dy=-1;dy<=1;dy++){
                            int x=i+dx;
                            int y=j+dy;
                            if(x>=0&&x<h&&y>=0&&y<w)
                                a[x][y]=0;
                        }
            }
        char[][] b=new char[h][w];
        for(int i=0;i<h;++i)Arrays.fill(b[i],'.');
        for(int i=0;i<h;++i)
            for(int j=0;j<w;++j)
                if(a[i][j]==1)
                    for(int dx=-1;dx<=1;++dx)
                        for(int dy=-1;dy<=1;dy++){
                            int x=i+dx;
                            int y=j+dy;
                            if(x>=0&&x<h&&y>=0&&y<w)
                                b[x][y]='#';
                        }
        for(int i=0;i<h;++i)
            if(!s[i].equals(new String(b[i]))){
                System.out.println("impossible");
                return;
            }
        System.out.println("possible");
        for(int i=0;i<h;++i){
            char[] r=new char[w];
            for(int j=0;j<w;++j)r[j]=a[i][j]==1?'#':'.';
            System.out.println(new String(r));
        }
    }
}