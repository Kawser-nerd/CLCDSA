// Author: Alejandro Sotelo Arevalo
package qualification;

import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.util.*;

public class D_HallOfMirrors {
  //--------------------------------------------------------------------------------
  private static String ID="D";
  private static String NAME="large";
  private static boolean STANDARD_OUTPUT=false;
  //--------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    BufferedReader reader=new BufferedReader(new FileReader(new File("data/"+ID+"-"+NAME+".in")));
    if (!STANDARD_OUTPUT) System.setOut(new PrintStream(new File("data/"+ID+"-"+NAME+".out")));
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      String w[]=reader.readLine().trim().split(" +");
      int H=Integer.parseInt(w[0]),W=Integer.parseInt(w[1]),D=Integer.parseInt(w[2]);
      Point point=null;
      Collection<Point> mirrors=new ArrayList<Point>();
      char[][] hall=new char[H][];
      for (int y=0; y<H; y++) {
        hall[y]=reader.readLine().toCharArray();
        for (int x=0; x<W; x++) {
          if (Character.toUpperCase(hall[y][x])=='X') {
            point=new Point(x,y);
          }
          else if (hall[y][x]=='#') {
            mirrors.add(new Point(x,y));
          }
        }
      }
      int result=simulateAngles(point,mirrors,D);
      System.out.println("Case #"+c+": "+result);
    }
    if (!STANDARD_OUTPUT) System.out.close();
    reader.close();
  }
  private static int simulateAngles(Point point, Collection<Point> mirrors, int D) {
    int count=0;
    for (int i=0; i<=D; i++) for (int j=1; j<=D; j++) if (gcd(i,j)==1) {
      for (int k=0; k<4; k++) {
        double minimum=simulateAngle(new Particle(point.x,point.y,new Angle(k==0?i:(k==1?-j:(k==2?-i:j)),k==0?j:(k==1?i:(k==2?-j:-i)))),mirrors,D);
        if (minimum<1E-12) count++;
      }
    }
    return count++;
  }
  private static long gcd(long a, long b) {
    return b==0?a:gcd(b,a%b);
  }
  private static double simulateAngle(Particle point, Collection<Point> mirrors, double distance) {
    //System.out.println("Simulation with x="+point.x+",y="+point.y+",angle="+point.angle.getValue()+",distance="+distance);
    Angle angle=point.angle;
    double x=point.x,y=point.y,d=distance,walked=0;
    double result=Double.POSITIVE_INFINITY;
    while (d>0) {
      double best=d;
      double nextX=x+d*angle.cos(),nextY=y+d*angle.sin();
      Angle nextAngle=angle;
      Collection<Collision> collisions=new ArrayList<Collision>();
      for (Point mirror:mirrors) {
        Collision collision=collision(new Particle(x,y,angle),mirror);
        if (collision!=null) {
          double dist=collision.distance(x,y);
          if (eq(dist,0)) {
            continue;
          }
          if (le(dist,best)) {
            collisions.clear();
          }
          if (leq(dist,best)) {
            collisions.add(collision);
            best=dist;
          }
        }
      }
      boolean destroyRay=collisions.isEmpty();
      if (collisions.size()==1) {
        Collision collision=collisions.iterator().next();
        nextX=collision.x;
        nextY=collision.y;
        if (collision.isCorner()==-1) {
          nextAngle=reflection(collision.side,angle);
        }
        else {
          destroyRay=collision.insideMirror(angle);
        }
      }
      else if (collisions.size()==2) {
        Iterator<Collision> iterator=collisions.iterator();
        Collision c1=iterator.next(),c2=iterator.next();
        nextX=c1.x;
        nextY=c1.y;
        if (c1.mirror.x==c2.mirror.x) {
          nextAngle=reflection(leq(x,c1.mirror.x)?3:1,angle);
        }
        else if (c1.mirror.y==c2.mirror.y) {
          nextAngle=reflection(leq(y,c1.mirror.y)?4:2,angle);
        }
        else {
          // The angle doesn't change
        }
      }
      else if (collisions.size()==3) {
        Collision collision=collisions.iterator().next();
        nextX=collision.x;
        nextY=collision.y;
        nextAngle=new Angle(-angle.x,-angle.y);
      }
      if (ge(walked,0)) result=Math.min(result,Line2D.ptSegDistSq(x,y,nextX,nextY,point.x,point.y));
      walked+=destroyRay?d:Point2D.distance(x,y,nextX,nextY);
      d=destroyRay?0:d-Point2D.distance(x,y,nextX,nextY);
      x=nextX;
      y=nextY;
      angle=nextAngle;
      //System.out.println("  nextX="+x+"nextY="+y+"result="+result+";"+walked);
    }
    return result;
  }
  private static Angle reflection(int side, Angle angle) {
    int x=angle.x,y=angle.y;
    switch (side) {
      case 1:
      case 3:
        return new Angle(-x,y);
      case 2:
      case 4:
        return new Angle(x,-y);
    }
    return angle;
  }
  private static Collision collision(Particle point, Point mirror) {
    Angle angle=point.angle;
    double xp=point.getX(),yp=point.getY();
    double xm=mirror.getX(),ym=mirror.getY();
    Collision result=null;
    if (angle.y==0&&angle.x>0) {
      result=leq(xp,xm-0.5)&&geq(yp,ym-0.5)&&leq(yp,ym+0.5)?new Collision(xm-0.5,yp,mirror,3):null;
    }
    else if (angle.y==0&&angle.x<0) {
      result=geq(xp,xm+0.5)&&geq(yp,ym-0.5)&&leq(yp,ym+0.5)?new Collision(xm+0.5,yp,mirror,1):null;
    }
    else if (angle.x==0&&angle.y>0) {
      result=leq(yp,ym-0.5)&&geq(xp,xm-0.5)&&leq(xp,xm+0.5)?new Collision(xp,ym-0.5,mirror,4):null;
    }
    else if (angle.x==0&&angle.y<0) {
      result=geq(yp,ym+0.5)&&geq(xp,xm-0.5)&&leq(xp,xm+0.5)?new Collision(xp,ym+0.5,mirror,2):null;
    }
    else {
      double ma=angle.tan(),mb=angle.atan();
      double xc=xp+angle.x,yc=yp+angle.y;
      double x1=xm-0.5,y1=yp+ma*(x1-xp);
      double x2=xm+0.5,y2=yp+ma*(x2-xp);
      double y3=ym-0.5,x3=xp+mb*(y3-yp);
      double y4=ym+0.5,x4=xp+mb*(y4-yp);
      Collection<Collision> collection=new ArrayList<Collision>(4);
      if (geq(y1,ym-0.5)&&leq(y1,ym+0.5)&&(xc>xp)==(x1>xp)) collection.add(new Collision(x1,y1,mirror,3));
      if (geq(y2,ym-0.5)&&leq(y2,ym+0.5)&&(xc<xp)==(x2<xp)) collection.add(new Collision(x2,y2,mirror,1));
      if (geq(x3,xm-0.5)&&leq(x3,xm+0.5)&&(yc>yp)==(y3>yp)) collection.add(new Collision(x3,y3,mirror,4));
      if (geq(x4,xm-0.5)&&leq(x4,xm+0.5)&&(yc<yp)==(y4<yp)) collection.add(new Collision(x4,y4,mirror,2));
      for (Collision c:collection) {
        if (result==null||c.distance(point)<result.distance(point)) result=c;
      }
    }
    return result!=null&&ge(result.distance(point),0)?result:null;
  }
  private static double EPSILON=1E-8;
  private static boolean eq(double a, double b) {
    return Math.abs(a-b)<EPSILON;
  }
  private static boolean leq(double a, double b) {
    return a<=b+EPSILON;
  }
  private static boolean geq(double a, double b) {
    return a>=b-EPSILON;
  }
  private static boolean le(double a, double b) {
    return a<b-EPSILON;
  }
  private static boolean ge(double a, double b) {
    return a>b+EPSILON;
  }
  private static class Particle extends Point2D {
    private double x;
    private double y;
    private Angle angle;
    public Particle(double x, double y, Angle angle) {
      this.x=x;
      this.y=y;
      this.angle=angle;
    }
    public double getX() {
      return x;
    }
    public double getY() {
      return y;
    }
    public void setLocation(double x, double y) {
      this.x=x;
      this.y=y;
    }
  }
  private static class Collision extends Point2D {
    private double x;
    private double y;
    private Point mirror;
    private int side;
    public Collision(double x, double y, Point mirror, int side) {
      this.x=x;
      this.y=y;
      this.mirror=mirror;
      this.side=side;
    }
    public int isCorner() {
      double xm=mirror.getX(),ym=mirror.getY();
      if (eq(distance(xm+0.5,ym-0.5),0)) return 1;
      if (eq(distance(xm+0.5,ym+0.5),0)) return 2;
      if (eq(distance(xm-0.5,ym+0.5),0)) return 3;
      if (eq(distance(xm-0.5,ym-0.5),0)) return 4;
      return -1;
    }
    public boolean insideMirror(Angle angle) {
      double xp=x+0.5*angle.cos(),yp=y+0.5*angle.sin();
      double xm=mirror.getX(),ym=mirror.getY();
      return geq(xp,xm-0.5)&&leq(xp,xm+0.5)&&geq(yp,ym-0.5)&&leq(yp,ym+0.5);
    }
    public double getX() {
      return x;
    }
    public double getY() {
      return y;
    }
    public void setLocation(double x, double y) {
      this.x=x;
      this.y=y;
    }
  }
  private static class Angle {
    private int x;
    private int y;
    private double r;
    public Angle(int x, int y) {
      this.x=x;
      this.y=y;
      r=Math.sqrt(1.0*x*x+1.0*y*y);
    }
    public double tan() {
      return 1.0*y/x;
    }
    public double atan() {
      return 1.0*x/y;
    }
    public double cos() {
      return 1.0*x/r;
    }
    public double sin() {
      return 1.0*y/r;
    }
    @SuppressWarnings("unused")
    public double getDegrees() {
      return Math.toDegrees(Math.atan2(y,x));
    }
    @SuppressWarnings("unused")
    public double getRadians() {
      return Math.atan2(y,x);
    }
  }
}
