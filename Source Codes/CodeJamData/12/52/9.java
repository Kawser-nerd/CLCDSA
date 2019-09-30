

import java.io.*;
import java.util.*;

public class Havannah {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    int S;
    int M;
    Point[] moves;
    Status[][] map;
    int currMove;
    
    public void reset() {
        map = new Status[S*2+1][S*2+1];
    }
    
    public boolean gotRing(int x, int y) {
        for(int dir = 0; dir <= 3; dir++) {
            Status statusAtDir = statusAtDir(x,y,dir);
            if(statusAtDir!=null && statusAtDir(x,y,dir+1)==null) {
                for(int nextDir = dir+2; nextDir <= 5; nextDir++) {
                    Status statusAtNextDir = statusAtDir(x,y,nextDir);
                    if(statusAtNextDir!=null && statusAtDir(x,y,(nextDir+1)%6)==null) {
                        Set<Marker> markers = new HashSet<Marker>(statusAtDir.markers);
                        markers.retainAll(statusAtNextDir.markers);
                        for(Marker marker : markers) {
                            if(marker.type==POINT) return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    
    public Status newStatus(int x, int y) {
        Status res = new Status();
        if(isCorner(x,y)) res.markers.add(new Marker(CORNER,new Point(x,y)));
        Point pointForEdge = pointForEdge(x,y);
        if(pointForEdge!=null) res.markers.add(new Marker(EDGE,pointForEdge));
        if(pointToSave(x,y)) res.markers.add(new Marker(POINT,new Point(x,y)));
        for(int dir = 0; dir <= 5; dir++) {
            Status statusAtDir = statusAtDir(x,y,dir);
            if(statusAtDir!=null) {
                res.markers.addAll(statusAtDir.markers);
            }
        }    
        List<Point> points = new ArrayList<Point>();
        for(Marker marker : res.markers) {
            if(marker.type==POINT) {
                points.add(marker.point);
            }
        }
        Collections.sort(points);
        for(int i = 1; i < points.size(); i++) {
            res.markers.remove(points.get(i));
        }
        return res;
    }
    
    public String victory(int x, int y, Status status) {
        boolean ring = gotRing(x,y);
        int corners = 0;
        int edges = 0;
        for(Marker marker : status.markers) {
            if(marker.type==CORNER) corners++;
            if(marker.type==EDGE) edges++;
        }
        boolean fork = edges >= 3;
        boolean bridge = corners >= 2;
        if(!(bridge||fork||ring)) return null;
        StringBuilder sb = new StringBuilder();
        if(bridge) sb.append("bridge");
        if(fork) {
            if(bridge) sb.append("-");
            sb.append("fork");
        }
        if(ring) {
            if(bridge||fork) sb.append("-");
            sb.append("ring");
        }
        sb.append(" in move ");
        sb.append((currMove+1));
        return sb.toString();
    }
    
    public void propagate(int x, int y, Set<Marker> markers) {
        Status status = map[x][y];
        if(status==null) return;
        if(status.counter >= currMove) return;
        status.counter = currMove;
        status.markers = markers;
        for(int dir = 0; dir <= 5; dir++) {
            Point pointAtDir = pointAtDir(x,y,dir);
            propagate(pointAtDir.x,pointAtDir.y,markers);
        }    
    }
    
    public void findAnswer() {
        for(currMove = 0; currMove < M; currMove++) {
            Point thisMove = moves[currMove];
            Status newStatus = newStatus(thisMove.x,thisMove.y);
            map[thisMove.x][thisMove.y] = newStatus;
            String victory = victory(thisMove.x, thisMove.y, newStatus);
            if(victory!=null) {
                System.out.println(victory);
                return;
            }
            if(currMove+1<M) propagate(thisMove.x,thisMove.y,newStatus.markers);
        }
        System.out.println("none");
    }
    
    public void doCase(int caseNumber) throws Exception {
        {
            String line = in.readLine();
            Scanner scan = new Scanner(line);
            S = scan.nextInt();
            M = scan.nextInt();
        }
        moves = new Point[M];
        for(int i = 0; i < M; i++) {
            String line = in.readLine();
            Scanner scan = new Scanner(line);
            moves[i] = new Point(scan.nextInt(),scan.nextInt());
        }
        reset();
        findAnswer();
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Havannah().run();
    }

    static class Point implements Comparable<Point>{
        int x, y;
        Point(int r, int c) {
            this.x = r;
            this.y = c;
        }
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + y;
            result = prime * result + x;
            return result;
        }
        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null) return false;
            if (getClass() != obj.getClass()) return false;
            Point other = (Point) obj;
            if (y != other.y) return false;
            if (x != other.x) return false;
            return true;
        }
        @Override
        public String toString() {
            return "Point [r=" + x + ", c=" + y + "]";
        }
        @Override
        public int compareTo(Point arg0) {
            if(arg0==null) return 1;
            int diff = x - arg0.x;
            if(diff!=0) return diff;
            return y - arg0.y;
        }
    }
    
    static int CORNER = 0;
    static int EDGE = 1;
    static int POINT = 2;
    
    static class Marker {
        int type;
        Point point;
        public Marker(int type, Point point) {
            this.type = type;
            this.point = point;
        }
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + ((point == null) ? 0 : point.hashCode());
            result = prime * result + type;
            return result;
        }
        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null) return false;
            if (getClass() != obj.getClass()) return false;
            Marker other = (Marker) obj;
            if (point == null) {
                if (other.point != null) return false;
            } else if (!point.equals(other.point)) return false;
            if (type != other.type) return false;
            return true;
        }
    }
    
    static class Status {
        int counter = -1;
        Set<Marker> markers = new HashSet<Havannah.Marker>();
    }
    
    public boolean isCorner(int x, int y) {
        boolean xGood = x==1 || x==S || x== 2*S-1;
        boolean yGood = y==1 || y==S || y== 2*S-1;
        return xGood && yGood && (x!=S || y!=S);
    }
    
    public boolean pointToSave(int x, int y) {
        return x%3==0;
    }
    
    static Point edge0 = new Point(9,9);
    static Point edge1 = new Point(5,9);
    static Point edge2 = new Point(1,5);
    static Point edge3 = new Point(1,1);
    static Point edge4 = new Point(5,1);
    static Point edge5 = new Point(9,5);
    
    public Point pointForEdge(int x, int y) {
        if(isCorner(x,y)) return null;
        if(y==2*S-1) return edge0;
        if(y==1) return edge3;
        if(x==2*S-1) return edge5;
        if(x==1) return edge2;
        if(x == y + S -1) return edge4;
        if(y == x + S -1) return edge1;
        return null;
    }
    
    public Point pointAtDir(int x, int y, int dir) {
        if(dir==0) return new Point(x+1,y+1);
        if(dir==1) return new Point(x,y+1);
        if(dir==2) return new Point(x-1,y);
        if(dir==3) return new Point(x-1,y-1);
        if(dir==4) return new Point(x,y-1);
        if(dir==5) return new Point(x+1,y);
        throw new AssertionError();
    }
    
    public Status statusAtDir(int x, int y, int dir) {
        Point point = pointAtDir(x,y,dir);
        return map[point.x][point.y];
    }
}
