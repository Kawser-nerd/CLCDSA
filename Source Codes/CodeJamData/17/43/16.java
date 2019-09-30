package gcj_r2.BeamingWithJoy;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.LinkedList;

public class BeamingWithJoy {
    
    static int HOR = 1;
    static int VER = 2;
    static int[][] moves = {{1, 0, VER}, {-1, 0, VER}, {0, 1, HOR}, {0, -1, HOR}};
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/gcj_r2/BeamingWithJoy/C-small-attempt0.in"));

        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t_i = 1; t_i <= T; t_i++) {
            String[] split = br.readLine().split(" ");
            int R = Integer.parseInt(split[0]);
            int C = Integer.parseInt(split[1]);

            char[][] grid = new char[R][];
            for (int r_i = 0; r_i < R; r_i++) {
                grid[r_i] = br.readLine().toCharArray();
            }

            boolean possible = solve(R, C, grid);

            int answer = 0;
            
            sb.append("Case #").append(t_i).append(": ").append(possible ? "POSSIBLE" : "IMPOSSIBLE").append("\n");
            if (possible) {
                for (int r = 0; r < R; r++) {
                    for (int c = 0; c < C; c++) {
                        sb.append(grid[r][c]);
                    }
                    sb.append('\n');
                }
            }
        }

        Files.write(Paths.get("src/gcj_r2/BeamingWithJoy/C-small-attempt0.out"), sb.toString().getBytes());
        System.out.println(sb.toString());
    }

    private static boolean solve(int R, int C, char[][] grid) {
        ArrayList<EmptyCell> cells = new ArrayList<>();
        ArrayList<Beam> beams = new ArrayList<>();

        EmptyCell[][] emptyCellGrid = new EmptyCell[R][C];

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == '.') {
                    EmptyCell cell = new EmptyCell(r, c);
                    cells.add(cell);
                    emptyCellGrid[r][c] = cell;
                }
                if (grid[r][c] == '-' || grid[r][c] == '|') {
                    Beam b = new Beam(beams.size(), r, c);
                    beams.add(b);
                }
            }
        }

        int[] pos = new int[beams.size()];
        for (int i = 0; i < pos.length; i++) {
            pos[i] = HOR | VER;
        }

        for (int beam_i = 0; beam_i < beams.size(); beam_i++) {
            Beam beam = beams.get(beam_i);
            
            PositionedBeam horBeam = new PositionedBeam(beam, HOR);
            PositionedBeam verBeam = new PositionedBeam(beam, VER);
            
            horBeam.opposite = verBeam;
            verBeam.opposite = horBeam;
            
            beam.positionedBeams[HOR] = horBeam;
            beam.positionedBeams[VER] = verBeam;
            
            for (int[] move : moves) {
                if ((pos[beam_i] & move[2]) == 0) continue;
                
                PositionedBeam posBeam = move[2] == VER ? verBeam : horBeam;
                
                int r = beam.r + move[0];
                int c = beam.c + move[1];
                while (c >= 0 && r >= 0 && c < C && r < R && grid[r][c] == '.') {
                    r += move[0];
                    c += move[1];
                }

                // we're ok
                if (c < 0 || r < 0 || c >= C || r >= R || grid[r][c] == '#') continue;

                // hit another beam
                if (grid[r][c] == '|' || grid[r][c] == '-') {
                    pos[beam_i] ^= move[2];
                    posBeam.possible = false;
                }
            }

            // mark
            for (int[] move : moves) {
                if ((pos[beam_i] & move[2]) == 0) continue;

                PositionedBeam posBeam = move[2] == VER ? verBeam : horBeam;

                int r = beam.r + move[0];
                int c = beam.c + move[1];
                while (c >= 0 && r >= 0 && c < C && r < R && grid[r][c] == '.') {
                    emptyCellGrid[r][c].canBeShot.add(posBeam);
                    posBeam.canShoot.add(emptyCellGrid[r][c]);
                    r += move[0];
                    c += move[1];
                }
            }
        }

        for (int p : pos) {
            if (p == 0) {
                return false;
            }
        }

        while (true) {

            LinkedList<EmptyCell> q = new LinkedList<>();
            q.addAll(cells);
            while (!q.isEmpty()) {
                EmptyCell cell = q.pop();
                if (cell.canBeShot.size() == 0) {
                    return false;
                }
                if (cell.canBeShot.size() == 1) {
                    PositionedBeam chosen = cell.canBeShot.get(0);
                    pos[chosen.beam.i] = chosen.direction;

                    chosen.opposite.possible = false;
                    for (EmptyCell emptyCell : chosen.opposite.canShoot) {
                        emptyCell.canBeShot.remove(chosen.opposite);
                        q.add(emptyCell);
                    }
                    chosen.opposite.canShoot.clear();
                }
            }

            boolean allOk = true;
            for (int i = 0; i < pos.length; i++) {
                int p = pos[i];
                if (p == 3) {
                    allOk = false;

                    // choose any
                    int chosenDir = (int) Math.floor(Math.random() * 2) + 1;
                    pos[i] = chosenDir;
                    Beam beam = beams.get(i);
                    PositionedBeam chosen = beam.positionedBeams[chosenDir];
                    chosen.opposite.possible = false;
                    for (EmptyCell emptyCell : chosen.opposite.canShoot) {
                        emptyCell.canBeShot.remove(chosen.opposite);
                    }
                    chosen.opposite.canShoot.clear();

                    break;
                }
            }
            
            if (allOk) break;
        }

        for (int i = 0; i < pos.length; i++) {
            Beam beam = beams.get(i);
            grid[beam.r][beam.c] = pos[i] == HOR ? '-' : '|';
        }
        
        return true;
    }

    static class EmptyCell {
        int r, c;
        ArrayList<PositionedBeam> canBeShot = new ArrayList<>();
        public EmptyCell(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    
    static class Beam {
        int i, r, c;
        PositionedBeam[] positionedBeams = new PositionedBeam[3];
        
        public Beam(int i, int r, int c) {
            this.i = i;
            this.r = r;
            this.c = c;
        }
    }
    
    static class PositionedBeam {
        Beam beam;
        int direction;
        ArrayList<EmptyCell> canShoot = new ArrayList<>();
        boolean possible = true;
        PositionedBeam opposite;
        public PositionedBeam(Beam beam, int direction) {
            this.beam = beam;
            this.direction = direction;
        }
    }
}
