import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.math.*;

import static java.lang.System.out;

public class Round1BB {

    Kattio io;

    public void go() {
        try {
            io = new Kattio(System.in, new FileOutputStream(new File("Round1BB.out")));
            int zzz = io.nextInt();
            for (int zz = 0; zz < zzz; zz++) {
                int numHorses = io.nextInt();
                int[] horses = new int[6];
                String[] segments = new String[3];
                for (int i = 0; i < 6; i++) {
                    horses[i] = io.nextInt();
                }
                boolean impossible = false;
                impossible |= horses[1] > horses[4];
                impossible |= horses[3] > horses[0];
                impossible |= horses[5] > horses[2];
                impossible |= horses[1] != 0 && horses[1] == horses[4] && (horses[0] != 0 || horses[2] != 0 || horses[3] != 0 || horses[5] != 0);
                impossible |= horses[3] != 0 && horses[3] == horses[0] && (horses[1] != 0 || horses[2] != 0 || horses[4] != 0 || horses[5] != 0);
                impossible |= horses[5] != 0 && horses[5] == horses[2] && (horses[0] != 0 || horses[1] != 0 || horses[3] != 0 || horses[4] != 0);
                impossible |= (horses[2]-horses[5]) > (horses[4]-horses[1]) + (horses[0]-horses[3]);
                impossible |= (horses[4]-horses[1]) > (horses[2]-horses[5]) + (horses[0]-horses[3]);
                impossible |= (horses[0]-horses[3]) > (horses[4]-horses[1]) + (horses[2]-horses[5]);

                if (impossible) {
                    io.printf("Case #%d: IMPOSSIBLE%n", zz+1);
                    continue;
                }

                io.printf("Case #%d: ", zz+1);

                if (horses[1] != 0) {
                    if (!(horses[0] != 0 || horses[2] != 0 || horses[3] != 0 || horses[5] != 0)) {
                        while (horses[4] > 0) {
                            io.print('B');
                            horses[4]--;
                            if (horses[1] > 0) {
                                io.print('O');
                                horses[1]--;
                            }
                        }
                        io.println();
                        continue;
                    }
                    char[] chain = new char[horses[1] * 2 + 1];
                    for (int i = 0; i < horses[1]; i++) {
                        chain[i*2] = 'B';
                        chain[i*2+1] = 'O';
                    }
                    chain[chain.length-1] = 'B';
                    horses[4] -= horses[1];
                    horses[1] = 0;
                    segments[0] = new String(chain);
                } else {
                    segments[0] = "B";
                }

                if (horses[3] != 0) {
                    if (!(horses[1] != 0 || horses[2] != 0 || horses[4] != 0 || horses[5] != 0)) {
                        while (horses[0] > 0) {
                            io.print('R');
                            horses[0]--;
                            if (horses[3] > 0) {
                                io.print('G');
                                horses[3]--;
                            }
                        }
                        io.println();
                        continue;
                    }
                    char[] chain = new char[horses[3] * 2 + 1];
                    for (int i = 0; i < horses[3]; i++) {
                        chain[i*2] = 'R';
                        chain[i*2+1] = 'G';
                    }
                    chain[chain.length-1] = 'R';
                    horses[0] -= horses[3];
                    horses[3] = 0;
                    segments[1] = new String(chain);
                } else {
                    segments[1] = "R";
                }

                if (horses[5] != 0) {
                    if (!(horses[0] != 0 || horses[1] != 0 || horses[3] != 0 || horses[4] != 0)) {
                        while (horses[2] > 0) {
                            io.print('Y');
                            horses[2]--;
                            if (horses[5] > 0) {
                                io.print('V');
                                horses[5]--;
                            }
                        }
                        io.println();
                        continue;
                    }
                    char[] chain = new char[horses[5] * 2 + 1];
                    for (int i = 0; i < horses[5]; i++) {
                        chain[i*2] = 'Y';
                        chain[i*2+1] = 'V';
                    }
                    chain[chain.length-1] = 'Y';
                    horses[2] -= horses[5];
                    horses[5] = 0;
                    segments[2] = new String(chain);
                } else {
                    segments[2] = "Y";
                }

                StringBuilder sb = new StringBuilder();

                if (horses[0] >= horses[2] && horses[0] >= horses[4]) {
                    while (horses[0] > 1) {
                        sb.append('R');
                        horses[0]--;
                        if (horses[2] >  horses[4]) {
                            sb.append('Y');
                            horses[2]--;
                        } else {
                            sb.append('B');
                            horses[4]--;
                        }
                    }
                    sb.append('R');
                    if (horses[2] > horses[4]) {
                        while (horses[2] > 0) {
                            sb.append('Y');
                            horses[2]--;
                            if (horses[4] > 0) {
                                sb.append('B');
                                horses[4]--;
                            }
                        }
                    } else {
                        while (horses[4] > 0) {
                            sb.append('B');
                            horses[4]--;
                            if (horses[2] > 0) {
                                sb.append('Y');
                                horses[2]--;
                            }
                        }
                    }
                } else if (horses[2] >= horses[4] && horses[2] >= horses[0]) {
                    while (horses[2] > 1) {
                        sb.append('Y');
                        horses[2]--;
                        if (horses[0] > horses[4]) {
                            sb.append('R');
                            horses[0]--;
                        } else {
                            sb.append('B');
                            horses[4]--;
                        }
                    }
                    sb.append('Y');
                    if (horses[0] > horses[4]) {
                        while (horses[0] > 0) {
                            sb.append('R');
                            horses[0]--;
                            if (horses[4] > 0) {
                                sb.append('B');
                                horses[4]--;
                            }
                        }
                    } else {
                        while (horses[4] > 0) {
                            sb.append('B');
                            horses[4]--;
                            if (horses[0] > 0) {
                                sb.append('R');
                                horses[0]--;
                            }
                        }
                    }
                } else {
                    while (horses[4] > 1) {
                        sb.append('B');
                        horses[4]--;
                        if (horses[2] >  horses[0]) {
                            sb.append('Y');
                            horses[2]--;
                        } else {
                            sb.append('R');
                            horses[0]--;
                        }
                    }
                    sb.append('B');
                    if (horses[2] > horses[0]) {
                        while (horses[2] > 0) {
                            sb.append('Y');
                            horses[2]--;
                            if (horses[0] > 0) {
                                sb.append('R');
                                horses[0]--;
                            }
                        }
                    } else {
                        while (horses[0] > 0) {
                            sb.append('R');
                            horses[0]--;
                            if (horses[2] > 0) {
                                sb.append('Y');
                                horses[2]--;
                            }
                        }
                    }
                }

                io.println(sb.toString().replaceFirst("B", segments[0]).replaceFirst("R", segments[1]).replaceFirst("Y", segments[2]));
            }

            io.flush();
            io.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Round1BB().go();
    }

    private class Kattio extends PrintWriter {

        private BufferedReader r;
        private String line;
        private StringTokenizer st;
        private String token;

        public Kattio(InputStream i) {
            super(new BufferedOutputStream(System.out));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public Kattio(InputStream i, OutputStream o) {
            super(new BufferedOutputStream(o));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public boolean hasNext() {
            return peekToken() != null;
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public String next() {
            return nextToken();
        }

        public String nextLine() {
            token = null;
            st = null;
            try {
                return r.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        private String peekToken() {
            if (token == null)
                try {
                    while (st == null || !st.hasMoreTokens()) {
                        line = r.readLine();
                        if (line == null) return null;
                        st = new StringTokenizer(line);
                    }
                    token = st.nextToken();
                } catch (IOException e) {
                }
            return token;
        }

        private String nextToken() {
            String ans = peekToken();
            token = null;
            return ans;
        }
    }
}
