import java.util.*;

class C {
    public static void main (String [] arg) {
        Scanner sc = new Scanner(System.in);
        int TT = sc.nextInt();
        for (int ii = 1; ii<= TT; ++ii) {
            int R = sc.nextInt();
            int C = sc.nextInt();
            char [][] Grid = new char [R][];
            boolean [][] canchange = new boolean[R][C];
            for (int i = 0; i<R; ++i) {
                Grid[i] = sc.next().toCharArray();
            }
            boolean impossible = false;
            A : for (int i = 0; i<R; ++i) {
                for (int j = 0; j<C; ++j) {
                    if (Grid[i][j] != '-' && Grid[i][j] != '|') continue;
                    if (Grid[i][j] == '|') { 
                        Grid[i][j] = '-';
                    }
                    boolean canSideways = false;
                    if (Grid[i][j] == '-') {
                        for (int j2 = j-1; j2>=0; --j2) {
                            if (Grid[i][j2] == '#') break;
                            if (Grid[i][j2] == '-' || Grid[i][j2] == '|') { impossible=true;}
                        }
                        for (int j2 = j+1; j2<C; ++j2) {
                            if (Grid[i][j2] == '#') break;
                            if (Grid[i][j2] == '-' || Grid[i][j2] == '|') { impossible=true;}
                        }
                        if (impossible) {
                            Grid[i][j] = '|';
                            impossible = false;
                        } else {
                            Grid[i][j] = '|';
                            canSideways = true;
                        }
                    }
                    boolean canVertical = true;
                    
                    if (Grid[i][j] == '|') {
                        for (int i2 = i-1; i2>=0; --i2) {
                            if (Grid[i2][j] == '#') break;
                            if (Grid[i2][j] == '-' || Grid[i2][j] == '|') { 
                                if (canSideways) {canVertical = false; break;}
                                impossible=true; break A;
                            }
                        }
                        for (int i2 = i+1; i2<R; ++i2) {
                            if (Grid[i2][j] == '#') break;
                            if (Grid[i2][j] == '-' || Grid[i2][j] == '|') { 
                                if (canSideways) {canVertical = false; break;}
                                impossible=true; break A;
                            }
                        }
                    }
                    if (!canVertical) Grid[i][j] = '-';
                    if (canSideways && canVertical) canchange[i][j] = true;
                }   
            }
            if (impossible) {
                System.out.printf("Case #%d: IMPOSSIBLE\n", ii);
                continue;
            }
            
            int [] CNT = new int [R];
            for (int j = 0; j<=C; ++j) {
                if (j != C) for (int i = 0; i<R; ++i) if (Grid[i][j] == '.') CNT[i]++;
                for (int i = 0; i<R; ++i) {
                    if (j == C || Grid[i][j] == '#') {
                        if (CNT[i] == 0) continue;
                        int cntbeams = 0;
                        int j3 = 0;
                        for (int j2 = j-1; j2>=0; --j2) {
                            if (Grid[i][j2] == '#') break;
                            if (Grid[i][j2] == '|' || Grid[i][j2] == '-') {
                                cntbeams++;
                                j3 = j2;
                            }
                        }
                        // '#....-....
                        if (cntbeams == 1) {
                            if (canchange[i][j3] || Grid[i][j3] == '-') {
                                Grid[i][j3] = '-';
                                canchange[i][j3] = false;
                                continue;
                            }
                        }
                        // '#|||||||| or #.......
                        for (int j2 = j-1; j2>=0 && Grid[i][j2] != '#' && !impossible; --j2) {
                            if (Grid[i][j2] != '.') continue;
                            boolean hasCoverage = false;
                            for (int i1 = i-1; i1>=0 && Grid[i1][j2] != '#'; --i1) {
                                if (Grid[i1][j2] == '|') { canchange[i1][j2] = false; hasCoverage = true; break;}
                                if (Grid[i1][j2] == '-' && canchange[i1][j2]) {
                                    Grid[i1][j2] = '|';
                                    canchange[i1][j2] = false;
                                    hasCoverage = true;
                                    break;
                                }
                            }
                            for (int i1 = i+1; i1<R && Grid[i1][j2] != '#' && !hasCoverage; ++i1) {
                                if (Grid[i1][j2] == '|') { canchange[i1][j2] = false; hasCoverage = true; break;}
                                if (Grid[i1][j2] == '-' && canchange[i1][j2]) {
                                    Grid[i1][j2] = '|';
                                    canchange[i1][j2] = false;
                                    hasCoverage = true;
                                    break;
                                }
                            }
                            if (!hasCoverage) {
                                impossible = true;
                            }
                        }
                    }
                }
            }
            if (impossible) {
                System.out.printf("Case #%d: IMPOSSIBLE\n", ii);
                continue;
            }
                System.out.printf("Case #%d: POSSIBLE\n", ii);
                for (int i = 0; i<R; ++i) {
                    System.out.println(new String(Grid[i]));
                }
        }
    }
}